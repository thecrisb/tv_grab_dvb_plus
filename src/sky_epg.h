#ifndef __LOADEPG_H__
#define __LOADEPG_H__

/*
 * loadepg.h
 *
 * Routines to decode Sky and MediaHigway EPG data
 * and generate xmltv files.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

//#define USETHREADS

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <poll.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/dvb/frontend.h>
#include <linux/dvb/dmx.h>
#include "libsi/section.h"
#include "libsi/descriptor.h"

#include "formats.h"

#define DVB_DEVICE_DEMUX "/dev/dvb/adapter%i/demux0"

#define LOADEPG_FILE_CONF "epg.conf"
#define LOADEPG_FILE_EQUIV "epg.equiv"

#define FILE_EPG_TMP "epg.tmp"
#define FILE_EPG_ERR "epg.err"
#define FILE_EPG_CHANNELS "epg.channels"

#define SKY_AU_DICT	"dict.skyau"
#define SKY_AU_THEMES	"themes.skyau"

#define SKY_IT_DICT	"dict.skyit"
#define SKY_IT_THEMES	"themes.skyit"

#define SKY_UK_DICT	"dict.skyuk"
#define SKY_UK_THEMES	"themes.skyuk"

#define MAX_ACTIVE_FILTERS 6
#define MAX_PROVIDERS 64

#define MAX_BOUQUETS 256
#define MAX_THEMES 4096
#define MAX_CHANNELS 4096
#define MAX_TITLES 262144
#define MAX_SUMMARIES 262144

#define MAX_BUFFER_SIZE_CHANNELS 1048576
#define MAX_BUFFER_SIZE_TITLES 4194304
#define MAX_BUFFER_SIZE_SUMMARIES 33554432

#define TIMEOUT_CONTROL 90 // seconds
#define TIMEOUT_FILTER 5000 // ms
#define TIMEOUT_ROTOR 30 // seconds
#define MAX_SKY 10 // number of unique sky channel numbers for a particular SID
struct sNode {
	char *Value;
	struct sNode *P0;
	struct sNode *P1;
};

typedef struct sNode sNodeH;

typedef struct {
	char *Directory;
	int DvbAdapterHasRotor;
	int DvbAdapterNumber;
	int EnableOsdMessages;
	int UseFileEquivalents;
} sConfig;

typedef struct {
	unsigned short int OriginalSourceId;
	unsigned short int OriginalNid;
	unsigned short int OriginalTid;
	unsigned short int OriginalSid;
	unsigned short int OriginalRid;
	unsigned short int EquivSourceId;
	unsigned short int EquivNid;
	unsigned short int EquivTid;
	unsigned short int EquivSid;
	unsigned short int EquivRid;
} sEquivChannel;

typedef struct {
	unsigned char Name[256];
} sTheme;

class sChannel {
public:
	unsigned short int ChannelId;
	unsigned short int Nid;
	unsigned short int Tid;
	unsigned short int Sid;
	unsigned short int SkyCount;
	unsigned short int SkyNumber;
	unsigned short int BouquetID;
	unsigned short Flags;
	unsigned int RegionMask;
	unsigned char ChannelType;
	char * name;
	char * shortname;
	char * providername;
	unsigned int pData;
	unsigned int lenData;
	bool IsFound;
	bool IsNameUpdated;

	sChannel() {
		memset(this, 0, sizeof(sChannel));
	}
	~sChannel() {
		if (name)
			free(name);
		if (shortname)
			free(shortname);
		if (providername)
			free(providername);
	}
};

typedef struct {
	unsigned short int BouquetId;
	short int SectionNumber[256];
	short int LastSectionNumber;
	const char * Name;
	const char * Code;
} sBouquet;

typedef struct {
	unsigned short int ChannelId;
	unsigned short int ThemeId;
	unsigned short int MjdTime;
	unsigned short int EventId;
	unsigned int StartTime;
	unsigned int Duration;
	unsigned char SummaryAvailable;
	unsigned int pData;
	unsigned int lenData;
} sTitle;

typedef struct {
	unsigned short int ChannelId;
	unsigned short int MjdTime;
	unsigned short int EventId;
	unsigned int pData;
	unsigned lenData;
} sSummary;

typedef struct {
	char *Title;
	int DataFormat;
	int SourceId;
	char *Parm1;
	char *Parm2;
	char *Parm3;
} sProvider;

typedef struct {
	int Fd;
	int Step;
	unsigned short int Pid;
	unsigned char Tid;
	unsigned char Mask;
} sFilter;

typedef struct {
	int Fd;
	int FilterId;
	bool IsBusy;
} sActiveFilter;

class cTaskLoadepg {
private:
	sNodeH H;
	sNodeH *nH;
	bool IsError;
	bool IsRunning;
	bool EndBAT;
	bool EndSDT;
	sChannel *firstSDTChannel;
	bool EndThemes;
	bool EndChannels;
	int pC;
	int pT;
	int pS;
	struct pollfd PFD[MAX_FILTERS];
	int nFilters;
	sFilter Filters[MAX_FILTERS];
	int nActiveFilters;
	sActiveFilter ActiveFilters[MAX_ACTIVE_FILTERS];
	unsigned char InitialBuffer[MAX_FILTERS][64];
	void AddFilter(unsigned short int Pid, unsigned char Tid = 0x00,
			unsigned char Mask = 0xff);
	void StartFilter(int FilterId);
	void StopFilter(int ActiveFilterId);
	void PollingFilters(int Timeout);
	void ReadBuffer(int FilterId, int Fd);
	void GetLocalTimeOffset(void);
	void GetSatelliteTimeOffset(int FilterId, unsigned char *Data, int Length);
	void GetChannelsSKYBOX(int FilterId, unsigned char *Data, int Length);
	void
			SupplementChannelsSKYBOX(int FilterId, unsigned char *Data,
					int Length);
	void GetTitlesSKYBOX(int FilterId, unsigned char *Data, int Length);
	void GetSummariesSKYBOX(int FilterId, unsigned char *Data, int Length);
	void GetThemesMHW1(int FilterId, unsigned char *Data, int Length);
	void GetChannelsMHW1(int FilterId, unsigned char *Data, int Length);
	void GetTitlesMHW1(int FilterId, unsigned char *Data, int Length);
	void GetSummariesMHW1(int FilterId, unsigned char *Data, int Length);
	void GetThemesMHW2(int FilterId, unsigned char *Data, int Length);
	void GetChannelsMHW2(int FilterId, unsigned char *Data, int Length);
	void GetTitlesMHW2(int FilterId, unsigned char *Data, int Length);
	void GetSummariesMHW2(int FilterId, unsigned char *Data, int Length);
	void CreateEpgDataFile(void);
	bool ReadFileDictionary(void);
	bool ReadFileThemes(void);
	void CleanString(unsigned char *String);
	unsigned char DecodeText[4096];
	unsigned char DecodeErrorText[4096];
	int DecodeHuffmanCode(unsigned char *Data, int Length);
	void CreateXmlChannels();
	void CreateEpgXml(void);
public:
	void Action(void);
	cTaskLoadepg(void);
	~cTaskLoadepg();
	void LoadFromSatellite(void);
	void LoadFromCable(void);
	void ShowSelectedInfo(void);
	void Stop();
	bool IsLoopRunning() const {
		return IsRunning;
	}
};

class EPGGrabber {
public:
	EPGGrabber();
	~EPGGrabber();
	void Grab();
};

extern char * bouquet_filter;
extern bool show_bouquets;

#endif
