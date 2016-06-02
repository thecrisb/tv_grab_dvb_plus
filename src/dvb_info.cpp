/*
 * dvbinfo.c
 *
 * Tables to map from id to text description for genre, aspect ratio and audio format.
 *
 * Taken from tv_grab_dvb - (c) Mark Bryars 2004
 * God bless vim and macros, this would have taken forever to format otherwise.
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

#include <stdint.h>
#include <stdlib.h>

#include "dvb_info.h"
#include "lookup.h"

const struct int_lookup_table description_table[] = {
    {0x00, "\0UNDEFINED CONTENT"},
    {0x01, "\0UNDEFINED CONTENT"},
    {0x02, "\0UNDEFINED CONTENT"},
    {0x03, "\0UNDEFINED CONTENT"},
    {0x04, "\0UNDEFINED CONTENT"},
    {0x05, "\0UNDEFINED CONTENT"},
    {0x06, "\0UNDEFINED CONTENT"},
    {0x07, "\0UNDEFINED CONTENT"},
    {0x08, "\0UNDEFINED CONTENT"},
    {0x09, "\0UNDEFINED CONTENT"},
    {0x0A, "\0UNDEFINED CONTENT"},
    {0x0B, "\0UNDEFINED CONTENT"},
    {0x0C, "\0UNDEFINED CONTENT"},
    {0x0D, "\0UNDEFINED CONTENT"},
    {0x0E, "\0UNDEFINED CONTENT"},
    {0x0F, "\0UNDEFINED CONTENT"},

    {0x10, "Movie / Drama"},
    {0x11, "Movie - detective/thriller"},
    {0x12, "Movie - adventure/western/war"},
    {0x13, "Movie - science fiction/fantasy/horror"},
    {0x14, "Movie - comedy"},
    {0x15, "Movie - soap/melodrama/folkloric"},
    {0x16, "Movie - romance"},
    {0x17, "Movie - serious/classical/religious/historical movie/drama"},
    {0x18, "Movie - adult movie/drama"},
    {0x19, "\0Movie - RESERVED"},
    {0x1A, "\0Movie - RESERVED"},
    {0x1B, "\0Movie - RESERVED"},
    {0x1C, "\0Movie - RESERVED"},
    {0x1D, "\0Movie - RESERVED"},
    {0x1E, "\0Movie - RESERVED"},
    {0x1F, NULL},

    {0x20, "News / Current Affairs"},
    {0x21, "New - news/weather report"},
    {0x22, "New - news magazine"},
    {0x23, "New - documentary"},
    {0x24, "New - discussion/interview/debate"},
    {0x25, "\0News - RESERVED"},
    {0x26, "\0News - RESERVED"},
    {0x27, "\0News - RESERVED"},
    {0x28, "\0News - RESERVED"},
    {0x29, "\0News - RESERVED"},
    {0x2A, "\0News - RESERVED"},
    {0x2B, "\0News - RESERVED"},
    {0x2C, "\0News - RESERVED"},
    {0x2D, "\0News - RESERVED"},
    {0x2E, "\0News - RESERVED"},
    {0x2E, NULL},

    {0x30, "Show / Game Show"},
    {0x31, "Show - game show/quiz/contest"},
    {0x32, "Show - variety show"},
    {0x33, "Show - talk show"},
    {0x34, "\0Show - RESERVED"},
    {0x35, "\0Show - RESERVED"},
    {0x36, "\0Show - RESERVED"},
    {0x37, "\0Show - RESERVED"},
    {0x38, "\0Show - RESERVED"},
    {0x39, "\0Show - RESERVED"},
    {0x3A, "\0Show - RESERVED"},
    {0x3B, "\0Show - RESERVED"},
    {0x3C, "\0Show - RESERVED"},
    {0x3D, "\0Show - RESERVED"},
    {0x3E, "\0Show - RESERVED"},
    {0x3F, NULL},

    {0x40, "Sports"},
    {0x41, "Sports - special events (Olympic Games, World Cup etc.)"},
    {0x42, "Sports - sports magazines"},
    {0x43, "Sports - football/soccer"},
    {0x44, "Sports - tennis/squash"},
    {0x45, "Sports - team sports (excluding football)"},
    {0x46, "Sports - athletics"},
    {0x47, "Sports - motor sport"},
    {0x48, "Sports - water sport"},
    {0x49, "Sports - winter sports"},
    {0x4A, "Sports - equestrian"},
    {0x4B, "Sports - martial sports"},
    {0x4C, "\0Sports - RESERVED"},
    {0x4D, "\0Sports - RESERVED"},
    {0x4E, "\0Sports - RESERVED"},
    {0x4F, NULL},

    {0x50, "Childrens / Youth"},
    {0x51, "Children - pre-school children's programmes"},
    {0x52, "Children - entertainment programmes for 6 to 14"},
    {0x53, "Children - entertainment programmes for 10 to 16"},
    {0x54, "Children - informational/educational/school programmes"},
    {0x55, "Children - cartoons/puppets"},
    {0x56, "\0Children - RESERVED"},
    {0x57, "\0Children - RESERVED"},
    {0x58, "\0Children - RESERVED"},
    {0x59, "\0Children - RESERVED"},
    {0x5A, "\0Children - RESERVED"},
    {0x5B, "\0Children - RESERVED"},
    {0x5C, "\0Children - RESERVED"},
    {0x5D, "\0Children - RESERVED"},
    {0x5E, "\0Children - RESERVED"},
    {0x5F, NULL},

    {0x60, "Music / Ballet / Dance"},
    {0x61, "Music - rock/pop"},
    {0x62, "Music - serious music/classical music"},
    {0x63, "Music - folk/traditional music"},
    {0x64, "Music - jazz"},
    {0x65, "Music - musical/opera"},
    {0x66, "Music - ballet"},
    {0x67, "\0Music - RESERVED"},
    {0x68, "\0Music - RESERVED"},
    {0x69, "\0Music - RESERVED"},
    {0x6A, "\0Music - RESERVED"},
    {0x6B, "\0Music - RESERVED"},
    {0x6C, "\0Music - RESERVED"},
    {0x6D, "\0Music - RESERVED"},
    {0x6E, "\0Music - RESERVED"},
    {0x6F, NULL},

    {0x70, "Arts / Culture"},
    {0x71, "Arts - performing arts"},
    {0x72, "Arts - fine arts"},
    {0x73, "Arts - religion"},
    {0x74, "Arts - popular culture/traditional arts"},
    {0x75, "Arts - literature"},
    {0x76, "Arts - film/cinema"},
    {0x77, "Arts - experimental film/video"},
    {0x78, "Arts - broadcasting/press"},
    {0x79, "Arts - new media"},
    {0x7A, "Arts - arts/culture magazines"},
    {0x7B, "Arts - fashion"},
    {0x7C, "\0Arts - RESERVED"},
    {0x7D, "\0Arts - RESERVED"},
    {0x7E, "\0Arts - RESERVED"},
    {0x7F, NULL},

    {0x80, "Social / Policical / Economics"},
    {0x81, "Social - magazines/reports/documentary"},
    {0x82, "Social - economics/social advisory"},
    {0x83, "Social - remarkable people"},
    {0x84, "\0Social - RESERVED"},
    {0x85, "\0Social - RESERVED"},
    {0x86, "\0Social - RESERVED"},
    {0x87, "\0Social - RESERVED"},
    {0x88, "\0Social - RESERVED"},
    {0x89, "\0Social - RESERVED"},
    {0x8A, "\0Social - RESERVED"},
    {0x8b, "\0Social - RESERVED"},
    {0x8C, "\0Social - RESERVED"},
    {0x8D, "\0Social - RESERVED"},
    {0x8E, "\0Social - RESERVED"},
    {0x8F, NULL},

    {0x90, "Education / Science / Factual"},
    {0x91, "Education - nature/animals/environment"},
    {0x92, "Education - technology/natural sciences"},
    {0x93, "Education - medicine/physiology/psychology"},
    {0x94, "Education - foreign countries/expeditions"},
    {0x95, "Education - social/spiritual sciences"},
    {0x96, "Education - further education"},
    {0x97, "Education - languages"},
    {0x98, "\0Education - RESERVED"},
    {0x99, "\0Education - RESERVED"},
    {0x9A, "\0Education - RESERVED"},
    {0x9B, "\0Education - RESERVED"},
    {0x9C, "\0Education - RESERVED"},
    {0x9D, "\0Education - RESERVED"},
    {0x9E, "\0Education - RESERVED"},
    {0x9F, NULL},

    {0xA0, "Leisure / Hobbies"},
    {0xA1, "Leisure - tourism/travel"},
    {0xA2, "Leisure - handicraft"},
    {0xA3, "Leisure - motoring"},
    {0xA4, "Leisure - fitness &amp; health"},
    {0xA5, "Leisure - cooking"},
    {0xA6, "Leisure - advertizement/shopping"},
    {0xA7, "Leisure - gardening"},
    {0xA8, "\0Leisure - RESERVED"},
    {0xA9, "\0Leisure - RESERVED"},
    {0xAA, "\0Leisure - RESERVED"},
    {0xAB, "\0Leisure - RESERVED"},
    {0xAC, "\0Leisure - RESERVED"},
    {0xAD, "\0Leisure - RESERVED"},
    {0xAE, "\0Leisure - RESERVED"},
    {0xAF, NULL},

    // Special
    {0xB0, "Original Language"},
    {0xB1, "black &amp; white"},
    {0xB2, "unpublished"},
    {0xB3, "live broadcast"},
    {0xB4, "\0Characteristics - RESERVED"},
    {0xB5, "\0Characteristics - RESERVED"},
    {0xB6, "\0Characteristics - RESERVED"},
    {0xB7, "\0Characteristics - RESERVED"},
    {0xB8, "\0Characteristics - RESERVED"},
    {0xB9, "\0Characteristics - RESERVED"},
    {0xBA, "\0Characteristics - RESERVED"},
    {0xBB, "\0Characteristics - RESERVED"},
    {0xBC, "\0Characteristics - RESERVED"},
    {0xBD, "\0Characteristics - RESERVED"},
    {0xBE, "\0Characteristics - RESERVED"},
    {0xBF, NULL},

    {0xC0, "\0RESERVED"},
    {0xC1, "\0RESERVED"},
    {0xC2, "\0RESERVED"},
    {0xC3, "\0RESERVED"},
    {0xC4, "\0RESERVED"},
    {0xC5, "\0RESERVED"},
    {0xC6, "\0RESERVED"},
    {0xC7, "\0RESERVED"},
    {0xC8, "\0RESERVED"},
    {0xC9, "\0RESERVED"},
    {0xCA, "\0RESERVED"},
    {0xCB, "\0RESERVED"},
    {0xCC, "\0RESERVED"},
    {0xCD, "\0RESERVED"},
    {0xCE, "\0RESERVED"},
    {0xCF, "\0RESERVED"},

    {0xD0, "\0RESERVED"},
    {0xD1, "\0RESERVED"},
    {0xD2, "\0RESERVED"},
    {0xD3, "\0RESERVED"},
    {0xD4, "\0RESERVED"},
    {0xD5, "\0RESERVED"},
    {0xD6, "\0RESERVED"},
    {0xD7, "\0RESERVED"},
    {0xD8, "\0RESERVED"},
    {0xD9, "\0RESERVED"},
    {0xDA, "\0RESERVED"},
    {0xDB, "\0RESERVED"},
    {0xDC, "\0RESERVED"},
    {0xDD, "\0RESERVED"},
    {0xDE, "\0RESERVED"},
    {0xDF, "\0RESERVED"},

    {0xE0, "\0RESERVED"},
    {0xE1, "\0RESERVED"},
    {0xE2, "\0RESERVED"},
    {0xE3, "\0RESERVED"},
    {0xE4, "\0RESERVED"},
    {0xE5, "\0RESERVED"},
    {0xE6, "\0RESERVED"},
    {0xE7, "\0RESERVED"},
    {0xE8, "\0RESERVED"},
    {0xE9, "\0RESERVED"},
    {0xEA, "\0RESERVED"},
    {0xEB, "\0RESERVED"},
    {0xEC, "\0RESERVED"},
    {0xED, "\0RESERVED"},
    {0xEE, "\0RESERVED"},
    {0xEF, "\0RESERVED"},

    // UK Freeview custom id
    {0xF0, "Drama"},
    {0xF1, NULL},
    {0xF2, NULL},
    {0xF3, NULL},
    {0xF4, NULL},
    {0xF5, NULL},
    {0xF6, NULL},
    {0xF7, NULL},
    {0xF8, NULL},
    {0xF9, NULL},
    {0xFA, NULL},
    {0xFB, NULL},
    {0xFC, NULL},
    {0xFD, NULL},
    {0xFE, NULL},
    {0xFF, NULL},

    {-1, NULL}
};

const struct int_lookup_table aspect_table[] = {
    {0, "4:3"},         	// 4/3
    {1, "16:9"},		// 16/9 WITH PAN VECTORS
    {2, "16:9"},		// 16/9 WITHOUT
    {3, "2.21:1"},		// >16/9 or 2.21/1 XMLTV no likey
// 30 Hz
    {4, "4:3"},         	// 4/3
    {5, "16:9"},		// 16/9 WITH PAN VECTORS
    {6, "16:9"},		// 16/9 WITHOUT
    {7, "2.21:1"},		// >16/9 or 2.21/1 XMLTV no likey
// HDTV
    {8, "4:3"},         	// 4/3
    {9, "16:9"},		// 16/9 WITH PAN VECTORS
    {10, "16:9"},		// 16/9 WITHOUT
    {11, "2.21:1"},		// >16/9 or 2.21/1 XMLTV no likey
// HDTV 30Hz
    {12, "4:3"},         	// 4/3
    {13, "16:9"},		// 16/9 WITH PAN VECTORS
    {14, "16:9"},		// 16/9 WITHOUT
    {15, "2.21:1"},		// >16/9 or 2.21/1 XMLTV no likey
    
    {-1, NULL}
};

const struct int_lookup_table audio_table[] = {
    {0x01, "mono"},		//single mono
    {0x02, "mono"},		//dual mono - stereo??
    {0x03, "stereo"},
    {0x05, "surround"},
    {0x04, "bilingual"},	// multilingual/channel
    {0x40, "audio-subtitle"},	// visual impared sound
//    {0x41, "x-hardofhearing"},	// hard hearing sound
////+cmb
//    {0x42, "x-audiodescribed"},	// hard hearing sound
    {0x43, "stereo"},	// hard hearing sound
    {0x44, "audio-subtitle"},	// visual impared sound
//    {0x41, "x-hardofhearing"},	// hard hearing sound

    ////-cmb    

    {-1, "BAD"}
};

/*
 * Table to map from language to ISO 2 letter country code.
 */
const struct str_lookup_table languageid_table[] = {
    {"aar", "aa"},
    {"abk", "ab"},
    {"afr", "af"},
    {"aka", "ak"},
    {"amh", "am"},
    {"ara", "ar"},
    {"arg", "an"},
    {"asm", "as"},
    {"ava", "av"},
    {"ave", "ae"},
    {"aym", "ay"},
    {"aze", "az"},
    {"bak", "ba"},
    {"bam", "bm"},
    {"bel", "be"},
    {"ben", "bn"},
    {"bih", "bh"},
    {"bis", "bi"},
    {"bod", "bo"},
    {"tib", "bo"},
    {"bos", "bs"},
    {"bre", "br"},
    {"bul", "bg"},
    {"cat", "ca"},
    {"ces", "cs"},
    {"cze", "cs"},
    {"cha", "ch"},
    {"che", "ce"},
    {"chu", "cu"},
    {"chv", "cv"},
    {"cor", "kw"},
    {"cos", "co"},
    {"cre", "cr"},
    {"cym", "cy"},
    {"wel", "cy"},
    {"dan", "da"},
    {"deu", "de"},
    {"ger", "de"},
    {"div", "dv"},
    {"dzo", "dz"},
    {"ell", "el"},
    {"gre", "el"},
    {"eng", "en"},
    {"epo", "eo"},
    {"est", "et"},
    {"eus", "eu"},
    {"baq", "eu"},
    {"ewe", "ee"},
    {"fao", "fo"},
    {"fas", "fa"},
    {"per", "fa"},
    {"fij", "fj"},
    {"fin", "fi"},
    {"fra", "fr"},
    {"fre", "fr"},
    {"fry", "fy"},
    {"ful", "ff"},
    {"gla", "gd"},
    {"gle", "ga"},
    {"glg", "gl"},
    {"glv", "gv"},
    {"grn", "gn"},
    {"guj", "gu"},
    {"hat", "ht"},
    {"hau", "ha"},
    {"heb", "he"},
    {"her", "hz"},
    {"hin", "hi"},
    {"hmo", "ho"},
    {"hrv", "hr"},
    {"scr", "hr"},
    {"hun", "hu"},
    {"hye", "hy"},
    {"arm", "hy"},
    {"ibo", "ig"},
    {"ido", "io"},
    {"iii", "ii"},
    {"iku", "iu"},
    {"ile", "ie"},
    {"ina", "ia"},
    {"ind", "id"},
    {"ipk", "ik"},
    {"isl", "is"},
    {"ice", "is"},
    {"ita", "it"},
    {"jav", "jv"},
    {"jpn", "ja"},
    {"kal", "kl"},
    {"kan", "kn"},
    {"kas", "ks"},
    {"kat", "ka"},
    {"geo", "ka"},
    {"kau", "kr"},
    {"kaz", "kk"},
    {"khm", "km"},
    {"kik", "ki"},
    {"kin", "rw"},
    {"kir", "ky"},
    {"kom", "kv"},
    {"kon", "kg"},
    {"kor", "ko"},
    {"kua", "kj"},
    {"kur", "ku"},
    {"lao", "lo"},
    {"lat", "la"},
    {"lav", "lv"},
    {"lim", "li"},
    {"lin", "ln"},
    {"lit", "lt"},
    {"ltz", "lb"},
    {"lub", "lu"},
    {"lug", "lg"},
    {"mah", "mh"},
    {"mal", "ml"},
    {"mar", "mr"},
    {"mkd", "mk"},
    {"mac", "mk"},
    {"mlg", "mg"},
    {"mlt", "mt"},
    {"mol", "mo"},
    {"mon", "mn"},
    {"mri", "mi"},
    {"mao", "mi"},
    {"msa", "ms"},
    {"may", "ms"},
    {"mya", "my"},
    {"bur", "my"},
    {"nau", "na"},
    {"nav", "nv"},
    {"nbl", "nr"},
    {"nde", "nd"},
    {"ndo", "ng"},
    {"nep", "ne"},
    {"nld", "nl"},
    {"dut", "nl"},
    {"nno", "nn"},
    {"nob", "nb"},
    {"nor", "no"},
    {"nya", "ny"},
    {"oci", "oc"},
    {"oji", "oj"},
    {"ori", "or"},
    {"orm", "om"},
    {"oss", "os"},
    {"pan", "pa"},
    {"pli", "pi"},
    {"pol", "pl"},
    {"por", "pt"},
    {"pus", "ps"},
    {"que", "qu"},
    {"roh", "rm"},
    {"ron", "ro"},
    {"rum", "ro"},
    {"run", "rn"},
    {"rus", "ru"},
    {"sag", "sg"},
    {"san", "sa"},
    {"sin", "si"},
    {"slk", "sk"},
    {"slo", "sk"},
    {"slv", "sl"},
    {"sme", "se"},
    {"smo", "sm"},
    {"sna", "sn"},
    {"snd", "sd"},
    {"som", "so"},
    {"sot", "st"},
    {"spa", "es"},
    {"sqi", "sq"},
    {"alb", "sq"},
    {"srd", "sc"},
    {"srp", "sr"},
    {"scc", "sr"},
    {"ssw", "ss"},
    {"sun", "su"},
    {"swa", "sw"},
    {"swe", "sv"},
    {"tah", "ty"},
    {"tam", "ta"},
    {"tat", "tt"},
    {"tel", "te"},
    {"tgk", "tg"},
    {"tgl", "tl"},
    {"tha", "th"},
    {"tir", "ti"},
    {"ton", "to"},
    {"tsn", "tn"},
    {"tso", "ts"},
    {"tuk", "tk"},
    {"tur", "tr"},
    {"twi", "tw"},
    {"uig", "ug"},
    {"ukr", "uk"},
    {"urd", "ur"},
    {"uzb", "uz"},
    {"ven", "ve"},
    {"vie", "vi"},
    {"vol", "vo"},
    {"wln", "wa"},
    {"wol", "wo"},
    {"xho", "xh"},
    {"yid", "yi"},
    {"yor", "yo"},
    {"zha", "za"},
    {"zho", "zh"},
    {"chi", "zh"},
    {"zul", "zu"},
    {NULL, NULL},
};

/*
 * Lookup description
 * If the key is not found then return a manufactured channel id
 */
const char *lookup_description(int id) {
	return lookup(description_table, id);
}

/*
 * Lookup language
 */
const char *lookup_language(const u_char * l) {
	char lang[4];
	lang[0] = (char) l[0];
	lang[1] = (char) l[1];
	lang[2] = (char) l[2];
	lang[3] = '\0';

	const char *c = slookup(languageid_table, lang);
	return c ? c : lang;
}

/*
 * Lookup aspect
 */
const char *lookup_aspect(int id) {
	return lookup(aspect_table, id);
}

/*
 * Lookup audio
 */
const char *lookup_audio(int id) {
	return lookup(audio_table, id);
}
