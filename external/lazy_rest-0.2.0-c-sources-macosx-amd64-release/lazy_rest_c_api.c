/* Generated by Nimrod Compiler v0.9.6 */
/*   (c) 2014 Andreas Rumpf */
/* The generated code is subject to the original license. */
#define NIM_INTBITS 64
#include "nimbase.h"

#include <setjmp.h>
typedef struct cstate205012 cstate205012;
typedef struct E_Base E_Base;
typedef struct TY117411 TY117411;
typedef struct NimStringDesc NimStringDesc;
typedef struct TGenericSeq TGenericSeq;
typedef struct tstringtable127812 tstringtable127812;
typedef struct TY205044 TY205044;
typedef struct TY205048 TY205048;
typedef struct tcell44135 tcell44135;
typedef struct TNimType TNimType;
typedef struct TNimNode TNimNode;
typedef struct tcellset44147 tcellset44147;
typedef struct tgcheap46216 tgcheap46216;
typedef struct tcellseq44151 tcellseq44151;
typedef struct tpagedesc44143 tpagedesc44143;
typedef struct tmemregion26410 tmemregion26410;
typedef struct tsmallchunk25640 tsmallchunk25640;
typedef struct tllchunk26404 tllchunk26404;
typedef struct tbigchunk25642 tbigchunk25642;
typedef struct tintset25617 tintset25617;
typedef struct ttrunk25613 ttrunk25613;
typedef struct tavlnode26408 tavlnode26408;
typedef struct tgcstat46214 tgcstat46214;
typedef struct TNimObject TNimObject;
typedef struct TSafePoint TSafePoint;
typedef struct tkeyvaluepairseq127810 tkeyvaluepairseq127810;
typedef struct tkeyvaluepair127808 tkeyvaluepair127808;
typedef struct tbasechunk25638 tbasechunk25638;
typedef struct tfreecell25630 tfreecell25630;
struct  TGenericSeq  {
NI len;
NI reserved;
};
struct  NimStringDesc  {
  TGenericSeq Sup;
NIM_CHAR data[SEQ_DECL_SIZE];
};
typedef N_NIMCALL_PTR(NimStringDesc*, lr_nim_msg_handler) (NimStringDesc* filename, NI line, NI col, NU8 msgkind, NimStringDesc* arg);
typedef N_NIMCALL_PTR(NCSTRING, lr_c_msg_handler) (NCSTRING filename, int line, int col, NIM_CHAR msgkind, NCSTRING arg);
struct TY205044 {
lr_nim_msg_handler Field0;
lr_c_msg_handler Field1;
};
typedef N_NIMCALL_PTR(NimStringDesc*, lr_nim_find_file_handler) (NimStringDesc* currentfilename, NimStringDesc* targetfilename);
typedef N_NIMCALL_PTR(void, lr_c_find_file_handler) (NCSTRING currentfilename, NCSTRING targetfilename, NCSTRING outpath, int maxlength);
struct TY205048 {
lr_nim_find_file_handler Field0;
lr_c_find_file_handler Field1;
};
struct  cstate205012  {
E_Base* Errorrstfiletohtml;
E_Base* Errorrststringtohtml;
TY117411* Errorssaferstfiletohtml;
TY117411* Errorssaferststringtohtml;
NimStringDesc* Retsourcestringtohtml;
NimStringDesc* Retsourcefiletohtml;
tstringtable127812* Retparserstoptions;
NimStringDesc* Retrstfiletohtml;
NimStringDesc* Retrststringtohtml;
NimStringDesc* Retsaferstfiletohtml;
NimStringDesc* Retsaferststringtohtml;
TY117411* Retsetnormalerrorrst;
TY117411* Retsetsafeerrorrst;
tstringtable127812* Globaloptions;
TY205044 Msghandler;
TY205048 Findfilehandler;
int Findfilebuffersize;
};
struct  tcell44135  {
NI Refcount;
TNimType* Typ;
};
typedef N_NIMCALL_PTR(void, TY2689) (void* p, NI op);
typedef N_NIMCALL_PTR(void*, TY2694) (void* p);
struct  TNimType  {
NI size;
NU8 kind;
NU8 flags;
TNimType* base;
TNimNode* node;
void* finalizer;
TY2689 marker;
TY2694 deepcopy;
};
struct  tcellseq44151  {
NI Len;
NI Cap;
tcell44135** D;
};
struct  tcellset44147  {
NI Counter;
NI Max;
tpagedesc44143* Head;
tpagedesc44143** Data;
};
typedef tsmallchunk25640* TY26422[512];
typedef ttrunk25613* ttrunkbuckets25615[256];
struct  tintset25617  {
ttrunkbuckets25615 Data;
};
struct  tmemregion26410  {
NI Minlargeobj;
NI Maxlargeobj;
TY26422 Freesmallchunks;
tllchunk26404* Llmem;
NI Currmem;
NI Maxmem;
NI Freemem;
NI Lastsize;
tbigchunk25642* Freechunkslist;
tintset25617 Chunkstarts;
tavlnode26408* Root;
tavlnode26408* Deleted;
tavlnode26408* Last;
tavlnode26408* Freeavlnodes;
};
struct  tgcstat46214  {
NI Stackscans;
NI Cyclecollections;
NI Maxthreshold;
NI Maxstacksize;
NI Maxstackcells;
NI Cycletablesize;
NI64 Maxpause;
};
struct  tgcheap46216  {
void* Stackbottom;
NI Cyclethreshold;
tcellseq44151 Zct;
tcellseq44151 Decstack;
tcellset44147 Cycleroots;
tcellseq44151 Tempstack;
NI Recgclock;
tmemregion26410 Region;
tgcstat46214 Stat;
};
struct  TNimObject  {
TNimType* m_type;
};
struct  E_Base  {
  TNimObject Sup;
E_Base* parent;
NCSTRING name;
NimStringDesc* message;
NimStringDesc* trace;
};
typedef struct {
N_NIMCALL_PTR(NIM_BOOL, ClPrc) (E_Base* e, void* ClEnv);
void* ClEnv;
} TY14009;
struct  TSafePoint  {
TSafePoint* prev;
NI status;
jmp_buf context;
NIM_BOOL hasRaiseAction;
TY14009 raiseAction;
};
typedef N_NIMCALL_PTR(NimStringDesc*, TY205419) (NimStringDesc* currentfilename_205420, NimStringDesc* targetfilename_205421);
typedef N_NIMCALL_PTR(NimStringDesc*, TY205086) (NimStringDesc* filename_205087, NI line, NI col, NU8 msgkind, NimStringDesc* arg);
typedef NimStringDesc* TY159041[11];
struct  TNimNode  {
NU8 kind;
NI offset;
TNimType* typ;
NCSTRING name;
NI len;
TNimNode** sons;
};
struct tkeyvaluepair127808 {
NimStringDesc* Field0;
NimStringDesc* Field1;
};
struct  tstringtable127812  {
  TNimObject Sup;
NI Counter;
tkeyvaluepairseq127810* Data;
NU8 Mode;
};
typedef NI TY25620[8];
struct  tpagedesc44143  {
tpagedesc44143* Next;
NI Key;
TY25620 Bits;
};
struct  tbasechunk25638  {
NI Prevsize;
NI Size;
NIM_BOOL Used;
};
struct  tsmallchunk25640  {
  tbasechunk25638 Sup;
tsmallchunk25640* Next;
tsmallchunk25640* Prev;
tfreecell25630* Freelist;
NI Free;
NI Acc;
NF Data;
};
struct  tllchunk26404  {
NI Size;
NI Acc;
tllchunk26404* Next;
};
struct  tbigchunk25642  {
  tbasechunk25638 Sup;
tbigchunk25642* Next;
tbigchunk25642* Prev;
NI Align;
NF Data;
};
struct  ttrunk25613  {
ttrunk25613* Next;
NI Key;
TY25620 Bits;
};
typedef tavlnode26408* TY26414[2];
struct  tavlnode26408  {
TY26414 Link;
NI Key;
NI Upperbound;
NI Level;
};
struct  tfreecell25630  {
tfreecell25630* Next;
NI Zerofield;
};
struct TY117411 {
  TGenericSeq Sup;
  NimStringDesc* data[SEQ_DECL_SIZE];
};
struct tkeyvaluepairseq127810 {
  TGenericSeq Sup;
  tkeyvaluepair127808 data[SEQ_DECL_SIZE];
};
N_NIMCALL(NimStringDesc*, lr_stdout_msg_handler)(NimStringDesc* filename, NI line, NI col, NU8 msgkind, NimStringDesc* arg);
N_NIMCALL(NimStringDesc*, lr_unrestricted_find_file_handler)(NimStringDesc* currentfilename, NimStringDesc* targetfilename);
N_CDECL(void, lr_version_int)(NI32* major, NI32* minor, NI32* maintenance);
N_NIMCALL(NCSTRING, lr_version_str)(void);
N_NIMCALL(tstringtable127812*, lr_parse_rst_options)(NCSTRING options);
N_NIMCALL(tstringtable127812*, parserstoptions_158666)(NimStringDesc* options);
N_NIMCALL(NimStringDesc*, copyString)(NimStringDesc* src);
N_NIMCALL(NimStringDesc*, cstrToNimstr)(NCSTRING str);
static N_INLINE(void, asgnRef)(void** dest, void* src);
static N_INLINE(void, incref_50225)(tcell44135* c);
static N_INLINE(NIM_BOOL, canbecycleroot_47867)(tcell44135* c);
static N_INLINE(void, rtladdcycleroot_48629)(tcell44135* c);
N_NOINLINE(void, incl_44871)(tcellset44147* s, tcell44135* cell);
static N_INLINE(tcell44135*, usrtocell_47846)(void* usr);
static N_INLINE(void, decref_49804)(tcell44135* c);
static N_INLINE(void, rtladdzct_49404)(tcell44135* c);
N_NOINLINE(void, addzct_47817)(tcellseq44151* s, tcell44135* c);
N_NIMCALL(int, lr_set_global_rst_options)(NCSTRING options);
N_NIMCALL(void, lr_set_nim_msg_handler)(lr_nim_msg_handler func);
N_NIMCALL(NimStringDesc*, lr_nil_msg_handler)(NimStringDesc* filename, NI line, NI col, NU8 msgkind, NimStringDesc* arg);
N_NIMCALL(void, lr_set_c_msg_handler)(lr_c_msg_handler func);
N_NIMCALL(void, lr_set_nim_find_file_handler)(lr_nim_find_file_handler func);
N_NIMCALL(NimStringDesc*, lr_nil_find_file_handler)(NimStringDesc* currentfilename, NimStringDesc* targetfilename);
N_NIMCALL(void, lr_set_c_find_file_handler)(lr_c_find_file_handler func);
N_NIMCALL(int, lr_set_find_file_buffer_size)(int s);
N_NIMCALL(NCSTRING, lr_rst_string_to_html)(NCSTRING content_205785, NCSTRING filename_205786, tstringtable127812* config_205787);
N_NIMCALL(NimStringDesc*, copyStringRC1)(NimStringDesc* src);
static N_INLINE(void, nimGCunrefNoCycle)(void* p);
static N_INLINE(void, pushSafePoint)(TSafePoint* s);
N_NIMCALL(NimStringDesc*, rststringtohtml_201608)(NimStringDesc* content, NimStringDesc* filename, tstringtable127812* userconfig, lr_nim_find_file_handler findfile, lr_nim_msg_handler msghandler);
N_NIMCALL(NimStringDesc*, findfilecallbackwrapper_205418)(NimStringDesc* currentfilename_205420, NimStringDesc* targetfilename_205421);
N_NIMCALL(NimStringDesc*, rawNewString)(NI space);
N_NIMCALL(NimStringDesc*, rawNewString)(NI cap);
N_NIMCALL(NimStringDesc*, msgcallbackwrapper_205085)(NimStringDesc* filename_205087, NI line, NI col, NU8 msgkind, NimStringDesc* arg);
N_NIMCALL(NimStringDesc*, nsuFormatSingleElem)(NimStringDesc* formatstr, NimStringDesc* a);
static N_INLINE(void, popSafePoint)(void);
N_NIMCALL(NIM_BOOL, isObj)(TNimType* obj, TNimType* subclass);
static N_INLINE(E_Base*, getCurrentException)(void);
static N_INLINE(void, popCurrentException)(void);
N_NIMCALL(void, reraiseException)(void);
N_NIMCALL(NimStringDesc*, reprEnum)(NI e_80307, TNimType* typ);
static N_INLINE(void, asgnRefNoCycle)(void** dest, void* src);
N_NIMCALL(NCSTRING, lr_rst_string_to_html_error)(void);
N_NIMCALL(NCSTRING, lr_rst_file_to_html)(NCSTRING filename_205851, tstringtable127812* config_205852);
N_NIMCALL(NimStringDesc*, rstfiletohtml_202036)(NimStringDesc* filename, tstringtable127812* userconfig, lr_nim_find_file_handler findfile, lr_nim_msg_handler msghandler);
N_NIMCALL(NCSTRING, lr_rst_file_to_html_error)(void);
N_NIMCALL(NCSTRING, lr_safe_rst_string_to_html)(NCSTRING data_205915, NCSTRING filename_205916, NI32* errors, tstringtable127812* config_205919);
N_NIMCALL(void*, newSeqRC1)(TNimType* typ, NI len);
N_NIMCALL(NimStringDesc*, saferststringtohtml_203277)(NimStringDesc* content, NimStringDesc* filename, TY117411** errors_203283, tstringtable127812* userconfig, lr_nim_find_file_handler findfile, lr_nim_msg_handler msghandler);
N_NIMCALL(NCSTRING, lr_safe_rst_string_to_html_error)(int pos);
N_NIMCALL(NCSTRING, lr_safe_rst_file_to_html)(NCSTRING filename_206040, NI32* errors, tstringtable127812* config_206043);
N_NIMCALL(NimStringDesc*, saferstfiletohtml_203526)(NimStringDesc* filename, TY117411** errors_203531, tstringtable127812* userconfig, lr_nim_find_file_handler findfile, lr_nim_msg_handler msghandler);
N_NIMCALL(NCSTRING, lr_safe_rst_file_to_html_error)(int pos);
N_NIMCALL(NCSTRING, lr_source_string_to_html)(NCSTRING content_206163, NCSTRING filename_206164, NCSTRING language_206165, int numberlines_206166, tstringtable127812* config_206167);
N_NIMCALL(NimStringDesc*, sourcestringtohtml_203593)(NimStringDesc* content, NimStringDesc* filename_203596, NimStringDesc* language_203597, NIM_BOOL numberlines, tstringtable127812* userconfig);
N_NIMCALL(NCSTRING, lr_source_file_to_html)(NCSTRING filename_206199, NCSTRING language_206200, int numberlines_206201, tstringtable127812* config_206202);
N_NIMCALL(NimStringDesc*, sourcefiletohtml_203841)(NimStringDesc* filename, NimStringDesc* language, NIM_BOOL numberlines, tstringtable127812* userconfig);
N_NIMCALL(int, lr_set_normal_error_rst)(NCSTRING inputrst_206233, tstringtable127812* config_206234);
N_NIMCALL(TY117411*, setnormalerrorrst_204008)(NimStringDesc* inputrst, tstringtable127812* userconfig);
N_NIMCALL(NCSTRING, lr_set_normal_error_rst_error)(int pos);
N_NIMCALL(int, lr_set_safe_error_rst)(NCSTRING inputrst_206308, tstringtable127812* config_206309);
N_NIMCALL(TY117411*, setsafeerrorrst_204092)(NimStringDesc* inputrst, tstringtable127812* userconfig);
N_NIMCALL(NCSTRING, lr_set_safe_error_rst_error)(int pos);
static N_INLINE(void, initStackBottomWith)(void* locals);
N_NOINLINE(void, setStackBottom)(void* thestackbottom);
N_NOINLINE(void, systemInit)(void);
N_NOINLINE(void, systemDatInit)(void);
N_NOINLINE(void, HEX00_parseutilsInit)(void);
N_NOINLINE(void, HEX00_parseutilsDatInit)(void);
N_NOINLINE(void, HEX00_strutilsInit)(void);
N_NOINLINE(void, HEX00_strutilsDatInit)(void);
N_NOINLINE(void, HEX00_timesInit)(void);
N_NOINLINE(void, HEX00_timesDatInit)(void);
N_NOINLINE(void, HEX00_posixInit)(void);
N_NOINLINE(void, HEX00_posixDatInit)(void);
N_NOINLINE(void, HEX00_osInit)(void);
N_NOINLINE(void, HEX00_osDatInit)(void);
N_NOINLINE(void, HEX00_hashesInit)(void);
N_NOINLINE(void, HEX00_hashesDatInit)(void);
N_NOINLINE(void, HEX00_strtabsInit)(void);
N_NOINLINE(void, HEX00_strtabsDatInit)(void);
N_NOINLINE(void, HEX00_streamsInit)(void);
N_NOINLINE(void, HEX00_streamsDatInit)(void);
N_NOINLINE(void, HEX00_lexbaseInit)(void);
N_NOINLINE(void, HEX00_lexbaseDatInit)(void);
N_NOINLINE(void, HEX00_unicodeInit)(void);
N_NOINLINE(void, HEX00_unicodeDatInit)(void);
N_NOINLINE(void, HEX00_jsonInit)(void);
N_NOINLINE(void, HEX00_jsonDatInit)(void);
N_NOINLINE(void, HEX00_lrstastInit)(void);
N_NOINLINE(void, HEX00_lrstastDatInit)(void);
N_NOINLINE(void, HEX00_typetraitsInit)(void);
N_NOINLINE(void, HEX00_typetraitsDatInit)(void);
N_NOINLINE(void, HEX00_bb_systemInit)(void);
N_NOINLINE(void, HEX00_bb_systemDatInit)(void);
N_NOINLINE(void, HEX00_parsecfgInit)(void);
N_NOINLINE(void, HEX00_parsecfgDatInit)(void);
N_NOINLINE(void, HEX00_lconfigInit)(void);
N_NOINLINE(void, HEX00_lconfigDatInit)(void);
N_NOINLINE(void, HEX00_lrstInit)(void);
N_NOINLINE(void, HEX00_lrstDatInit)(void);
N_NOINLINE(void, HEX00_lhighliteInit)(void);
N_NOINLINE(void, HEX00_lhighliteDatInit)(void);
N_NOINLINE(void, HEX00_mathInit)(void);
N_NOINLINE(void, HEX00_mathDatInit)(void);
N_NOINLINE(void, HEX00_tablesInit)(void);
N_NOINLINE(void, HEX00_tablesDatInit)(void);
N_NOINLINE(void, HEX00_sequtilsInit)(void);
N_NOINLINE(void, HEX00_sequtilsDatInit)(void);
N_NOINLINE(void, HEX00_algorithmInit)(void);
N_NOINLINE(void, HEX00_algorithmDatInit)(void);
N_NOINLINE(void, HEX00_lrstgenInit)(void);
N_NOINLINE(void, HEX00_lrstgenDatInit)(void);
N_NOINLINE(void, HEX00_subexesInit)(void);
N_NOINLINE(void, HEX00_subexesDatInit)(void);
N_NOINLINE(void, HEX00_cookiesInit)(void);
N_NOINLINE(void, HEX00_cookiesDatInit)(void);
N_NOINLINE(void, HEX00_cgiInit)(void);
N_NOINLINE(void, HEX00_cgiDatInit)(void);
N_NOINLINE(void, HEX00_lazy_restInit)(void);
N_NOINLINE(void, HEX00_lazy_restDatInit)(void);
N_NOINLINE(void, lazy_rest_c_apiInit)(void);
N_NOINLINE(void, lazy_rest_c_apiDatInit)(void);
extern NIM_CONST TY159041 rstmessages_159040;
cstate205012 c_205061;
extern tgcheap46216 gch_46244;
extern TSafePoint* exchandler_15443;
extern TNimType NTI2855; /* EInvalidValue */
extern E_Base* currexception_15445;
extern TNimType NTI159007; /* TMsgKind */
extern TNimType NTI117411; /* seq[string] */

N_CDECL(void, lr_version_int)(NI32* major, NI32* minor, NI32* maintenance) {
	{
		if (!!(major == 0)) goto LA3;
		(*major) = ((int) 0);
	}
	LA3: ;
	{
		if (!!(minor == 0)) goto LA7;
		(*minor) = ((int) 2);
	}
	LA7: ;
	{
		if (!!(maintenance == 0)) goto LA11;
		(*maintenance) = ((int) 0);
	}
	LA11: ;
}

N_NIMCALL(NCSTRING, lr_version_str)(void) {
	NCSTRING result;
	result = 0;
	result = "0.2.0";
	return result;
}

static N_INLINE(NIM_BOOL, canbecycleroot_47867)(tcell44135* c) {
	NIM_BOOL result;
	result = 0;
	result = !((((*(*c).Typ).flags &(1<<((((NU8) 1))&7)))!=0));
	return result;
}

static N_INLINE(void, rtladdcycleroot_48629)(tcell44135* c) {
	{
		if (!!((((NI) ((NI)((*c).Refcount & 3))) == 3))) goto LA3;
		(*c).Refcount = (NI)((NI)((*c).Refcount & -4) | 3);
		incl_44871(&gch_46244.Cycleroots, c);
	}
	LA3: ;
}

static N_INLINE(void, incref_50225)(tcell44135* c) {
	(*c).Refcount = (NI)((NU64)((*c).Refcount) + (NU64)(8));
	{
		NIM_BOOL LOC3;
		LOC3 = 0;
		LOC3 = canbecycleroot_47867(c);
		if (!LOC3) goto LA4;
		rtladdcycleroot_48629(c);
	}
	LA4: ;
}

static N_INLINE(tcell44135*, usrtocell_47846)(void* usr) {
	tcell44135* result;
	result = 0;
	result = ((tcell44135*) ((NI)((NU64)(((NI) (usr))) - (NU64)(((NI)sizeof(tcell44135))))));
	return result;
}

static N_INLINE(void, rtladdzct_49404)(tcell44135* c) {
	addzct_47817(&gch_46244.Zct, c);
}

static N_INLINE(void, decref_49804)(tcell44135* c) {
	{
		(*c).Refcount -= 8;
		if (!((NU64)((*c).Refcount) < (NU64)(8))) goto LA3;
		rtladdzct_49404(c);
	}
	goto LA1;
	LA3: ;
	{
		NIM_BOOL LOC6;
		LOC6 = 0;
		LOC6 = canbecycleroot_47867(c);
		if (!LOC6) goto LA7;
		rtladdcycleroot_48629(c);
	}
	goto LA1;
	LA7: ;
	LA1: ;
}

static N_INLINE(void, asgnRef)(void** dest, void* src) {
	{
		tcell44135* LOC5;
		if (!!((src == NIM_NIL))) goto LA3;
		LOC5 = 0;
		LOC5 = usrtocell_47846(src);
		incref_50225(LOC5);
	}
	LA3: ;
	{
		tcell44135* LOC10;
		if (!!(((*dest) == NIM_NIL))) goto LA8;
		LOC10 = 0;
		LOC10 = usrtocell_47846((*dest));
		decref_49804(LOC10);
	}
	LA8: ;
	(*dest) = src;
}

N_NIMCALL(tstringtable127812*, lr_parse_rst_options)(NCSTRING options) {
	tstringtable127812* result;
	NimStringDesc* LOC1;
	result = 0;
	LOC1 = 0;
	{
		if (!options == 0) goto LA4;
		LOC1 = copyString(NIM_NIL);
	}
	goto LA2;
	LA4: ;
	{
		LOC1 = cstrToNimstr(options);
	}
	LA2: ;
	asgnRef((void**) &c_205061.Retparserstoptions, parserstoptions_158666(LOC1));
	result = c_205061.Retparserstoptions;
	return result;
}

N_NIMCALL(int, lr_set_global_rst_options)(NCSTRING options) {
	int result;
	NI LOC1;
	result = 0;
	asgnRef((void**) &c_205061.Globaloptions, lr_parse_rst_options(options));
	LOC1 = 0;
	{
		if (!c_205061.Globaloptions == 0) goto LA4;
		LOC1 = 0;
	}
	goto LA2;
	LA4: ;
	{
		LOC1 = 1;
	}
	LA2: ;
	result = ((int) (LOC1));
	return result;
}

N_NIMCALL(void, lr_set_nim_msg_handler)(lr_nim_msg_handler func) {
	{
		if (!func == 0) goto LA3;
		c_205061.Msghandler.Field0 = lr_nil_msg_handler;
	}
	goto LA1;
	LA3: ;
	{
		c_205061.Msghandler.Field0 = func;
	}
	LA1: ;
}

N_NIMCALL(void, lr_set_c_msg_handler)(lr_c_msg_handler func) {
	c_205061.Msghandler.Field1 = func;
}

N_NIMCALL(void, lr_set_nim_find_file_handler)(lr_nim_find_file_handler func) {
	{
		if (!func == 0) goto LA3;
		c_205061.Findfilehandler.Field0 = lr_nil_find_file_handler;
	}
	goto LA1;
	LA3: ;
	{
		c_205061.Findfilehandler.Field0 = func;
	}
	LA1: ;
}

N_NIMCALL(void, lr_set_c_find_file_handler)(lr_c_find_file_handler func) {
	c_205061.Findfilehandler.Field1 = func;
}

N_NIMCALL(int, lr_set_find_file_buffer_size)(int s) {
	int result;
	result = 0;
	{
		if (!(((NI32) 255) <= s)) goto LA3;
		c_205061.Findfilebuffersize = s;
	}
	LA3: ;
	result = c_205061.Findfilebuffersize;
	return result;
}

static N_INLINE(void, nimGCunrefNoCycle)(void* p) {
	tcell44135* c;
	c = usrtocell_47846(p);
	{
		(*c).Refcount -= 8;
		if (!((NU64)((*c).Refcount) < (NU64)(8))) goto LA3;
		rtladdzct_49404(c);
	}
	LA3: ;
}

static N_INLINE(void, pushSafePoint)(TSafePoint* s) {
	(*s).hasRaiseAction = NIM_FALSE;
	(*s).prev = exchandler_15443;
	exchandler_15443 = s;
}

N_NIMCALL(NimStringDesc*, findfilecallbackwrapper_205418)(NimStringDesc* currentfilename_205420, NimStringDesc* targetfilename_205421) {
	NimStringDesc* result;
	NimStringDesc* outpath;
	NCSTRING currentfilename;
	NCSTRING targetfilename;
	result = 0;
	outpath = rawNewString(((NI) (c_205061.Findfilebuffersize)));
	outpath->data[0] = 0;
	{
		if (!currentfilename_205420 == 0) goto LA3;
		currentfilename = NIM_NIL;
	}
	goto LA1;
	LA3: ;
	{
		currentfilename = currentfilename_205420->data;
	}
	LA1: ;
	{
		if (!targetfilename_205421 == 0) goto LA8;
		targetfilename = NIM_NIL;
	}
	goto LA6;
	LA8: ;
	{
		targetfilename = targetfilename_205421->data;
	}
	LA6: ;
	c_205061.Findfilehandler.Field1(currentfilename, targetfilename, ((NCSTRING) (&outpath->data[0])), c_205061.Findfilebuffersize);
	result = cstrToNimstr(((NCSTRING) (&outpath->data[0])));
	return result;
}

static N_INLINE(void, popSafePoint)(void) {
	exchandler_15443 = (*exchandler_15443).prev;
}

static N_INLINE(E_Base*, getCurrentException)(void) {
	E_Base* result;
	result = 0;
	result = currexception_15445;
	return result;
}

static N_INLINE(void, popCurrentException)(void) {
	asgnRef((void**) &currexception_15445, (*currexception_15445).parent);
}

N_NIMCALL(NimStringDesc*, msgcallbackwrapper_205085)(NimStringDesc* filename_205087, NI line, NI col, NU8 msgkind, NimStringDesc* arg) {
	NimStringDesc* result;
	NimStringDesc* reason;
	TSafePoint TMP787;
	NCSTRING filename;
	NIM_CHAR kind;
	NCSTRING msg;
	result = 0;
	reason = copyString(arg);
	pushSafePoint(&TMP787);
	TMP787.status = _setjmp(TMP787.context);
	if (TMP787.status == 0) {
		reason = nsuFormatSingleElem(rstmessages_159040[(msgkind)- 0], arg);
		popSafePoint();
	}
	else {
		popSafePoint();
		if (isObj(getCurrentException()->Sup.m_type, (&NTI2855))) {
			TMP787.status = 0;
			popCurrentException();
		}
	}
	if (TMP787.status != 0) reraiseException();
	{
		if (!filename_205087 == 0) goto LA6;
		filename = NIM_NIL;
	}
	goto LA4;
	LA6: ;
	{
		filename = filename_205087->data;
	}
	LA4: ;
	kind = reprEnum(msgkind, (&NTI159007))->data[1];
	msg = c_205061.Msghandler.Field1(filename, ((int) (line)), ((int) (col)), kind, reason->data);
	{
		if (!!(msg == 0)) goto LA11;
		result = cstrToNimstr(msg);
	}
	LA11: ;
	return result;
}

static N_INLINE(void, asgnRefNoCycle)(void** dest, void* src) {
	{
		tcell44135* c;
		if (!!((src == NIM_NIL))) goto LA3;
		c = usrtocell_47846(src);
		(*c).Refcount += 8;
	}
	LA3: ;
	{
		tcell44135* c;
		if (!!(((*dest) == NIM_NIL))) goto LA7;
		c = usrtocell_47846((*dest));
		{
			(*c).Refcount -= 8;
			if (!((NU64)((*c).Refcount) < (NU64)(8))) goto LA11;
			rtladdzct_49404(c);
		}
		LA11: ;
	}
	LA7: ;
	(*dest) = src;
}

N_NIMCALL(NCSTRING, lr_rst_string_to_html)(NCSTRING content_205785, NCSTRING filename_205786, tstringtable127812* config_205787) {
	NCSTRING result;
	tstringtable127812* config;
	NimStringDesc* filename;
	NimStringDesc* content;
	NimStringDesc* LOC16;
	TSafePoint TMP143;
	result = 0;
	{
		if (!(config_205787 == NIM_NIL)) goto LA3;
		config = c_205061.Globaloptions;
	}
	goto LA1;
	LA3: ;
	{
		config = config_205787;
	}
	LA1: ;
	{
		if (!filename_205786 == 0) goto LA8;
		filename = NIM_NIL;
	}
	goto LA6;
	LA8: ;
	{
		filename = cstrToNimstr(filename_205786);
	}
	LA6: ;
	{
		if (!content_205785 == 0) goto LA13;
		content = NIM_NIL;
	}
	goto LA11;
	LA13: ;
	{
		content = cstrToNimstr(content_205785);
	}
	LA11: ;
	LOC16 = 0;
	LOC16 = c_205061.Retrststringtohtml; c_205061.Retrststringtohtml = copyStringRC1(NIM_NIL);
	if (LOC16) nimGCunrefNoCycle(LOC16);
	asgnRef((void**) &c_205061.Errorrststringtohtml, NIM_NIL);
	pushSafePoint(&TMP143);
	TMP143.status = _setjmp(TMP143.context);
	if (TMP143.status == 0) {
		TY205419 LOC18;
		TY205086 LOC24;
		LOC18 = 0;
		{
			if (!!(c_205061.Findfilehandler.Field1 == 0)) goto LA21;
			LOC18 = findfilecallbackwrapper_205418;
		}
		goto LA19;
		LA21: ;
		{
			LOC18 = c_205061.Findfilehandler.Field0;
		}
		LA19: ;
		LOC24 = 0;
		{
			if (!!(c_205061.Msghandler.Field1 == 0)) goto LA27;
			LOC24 = msgcallbackwrapper_205085;
		}
		goto LA25;
		LA27: ;
		{
			LOC24 = c_205061.Msghandler.Field0;
		}
		LA25: ;
		asgnRefNoCycle((void**) &c_205061.Retrststringtohtml, rststringtohtml_201608(content, filename, config, LOC18, LOC24));
		{
			if (!c_205061.Retrststringtohtml == 0) goto LA32;
			result = NIM_NIL;
		}
		goto LA30;
		LA32: ;
		{
			result = c_205061.Retrststringtohtml->data;
		}
		LA30: ;
		popSafePoint();
	}
	else {
		popSafePoint();
		{
			TMP143.status = 0;
			asgnRef((void**) &c_205061.Errorrststringtohtml, getCurrentException());
			popCurrentException();
		}
	}
	if (TMP143.status != 0) reraiseException();
	return result;
}

N_NIMCALL(NCSTRING, lr_rst_string_to_html_error)(void) {
	NCSTRING result;
	result = 0;
	{
		if (!!(c_205061.Errorrststringtohtml == 0)) goto LA3;
		{
			if (!(*c_205061.Errorrststringtohtml).message == 0) goto LA7;
			result = NIM_NIL;
		}
		goto LA5;
		LA7: ;
		{
			result = (*c_205061.Errorrststringtohtml).message->data;
		}
		LA5: ;
	}
	LA3: ;
	return result;
}

N_NIMCALL(NCSTRING, lr_rst_file_to_html)(NCSTRING filename_205851, tstringtable127812* config_205852) {
	NCSTRING result;
	tstringtable127812* config;
	NimStringDesc* filename;
	NimStringDesc* LOC11;
	TSafePoint TMP788;
	result = 0;
	{
		if (!(config_205852 == NIM_NIL)) goto LA3;
		config = c_205061.Globaloptions;
	}
	goto LA1;
	LA3: ;
	{
		config = config_205852;
	}
	LA1: ;
	{
		if (!filename_205851 == 0) goto LA8;
		filename = NIM_NIL;
	}
	goto LA6;
	LA8: ;
	{
		filename = cstrToNimstr(filename_205851);
	}
	LA6: ;
	LOC11 = 0;
	LOC11 = c_205061.Retrstfiletohtml; c_205061.Retrstfiletohtml = copyStringRC1(NIM_NIL);
	if (LOC11) nimGCunrefNoCycle(LOC11);
	asgnRef((void**) &c_205061.Errorrstfiletohtml, NIM_NIL);
	pushSafePoint(&TMP788);
	TMP788.status = _setjmp(TMP788.context);
	if (TMP788.status == 0) {
		TY205419 LOC13;
		TY205086 LOC19;
		LOC13 = 0;
		{
			if (!!(c_205061.Findfilehandler.Field1 == 0)) goto LA16;
			LOC13 = findfilecallbackwrapper_205418;
		}
		goto LA14;
		LA16: ;
		{
			LOC13 = c_205061.Findfilehandler.Field0;
		}
		LA14: ;
		LOC19 = 0;
		{
			if (!!(c_205061.Msghandler.Field1 == 0)) goto LA22;
			LOC19 = msgcallbackwrapper_205085;
		}
		goto LA20;
		LA22: ;
		{
			LOC19 = c_205061.Msghandler.Field0;
		}
		LA20: ;
		asgnRefNoCycle((void**) &c_205061.Retrstfiletohtml, rstfiletohtml_202036(filename, config, LOC13, LOC19));
		{
			if (!c_205061.Retrstfiletohtml == 0) goto LA27;
			result = NIM_NIL;
		}
		goto LA25;
		LA27: ;
		{
			result = c_205061.Retrstfiletohtml->data;
		}
		LA25: ;
		popSafePoint();
	}
	else {
		popSafePoint();
		{
			TMP788.status = 0;
			asgnRef((void**) &c_205061.Errorrstfiletohtml, getCurrentException());
			popCurrentException();
		}
	}
	if (TMP788.status != 0) reraiseException();
	return result;
}

N_NIMCALL(NCSTRING, lr_rst_file_to_html_error)(void) {
	NCSTRING result;
	result = 0;
	{
		if (!!(c_205061.Errorrstfiletohtml == 0)) goto LA3;
		{
			if (!(*c_205061.Errorrstfiletohtml).message == 0) goto LA7;
			result = NIM_NIL;
		}
		goto LA5;
		LA7: ;
		{
			result = (*c_205061.Errorrstfiletohtml).message->data;
		}
		LA5: ;
	}
	LA3: ;
	return result;
}

N_NIMCALL(NCSTRING, lr_safe_rst_string_to_html)(NCSTRING data_205915, NCSTRING filename_205916, NI32* errors, tstringtable127812* config_205919) {
	NCSTRING result;
	tstringtable127812* config;
	NimStringDesc* filename;
	NimStringDesc* data;
	TY205419 LOC16;
	TY205086 LOC22;
	result = 0;
	{
		if (!(config_205919 == NIM_NIL)) goto LA3;
		config = c_205061.Globaloptions;
	}
	goto LA1;
	LA3: ;
	{
		config = config_205919;
	}
	LA1: ;
	{
		if (!filename_205916 == 0) goto LA8;
		filename = NIM_NIL;
	}
	goto LA6;
	LA8: ;
	{
		filename = cstrToNimstr(filename_205916);
	}
	LA6: ;
	{
		if (!data_205915 == 0) goto LA13;
		data = NIM_NIL;
	}
	goto LA11;
	LA13: ;
	{
		data = cstrToNimstr(data_205915);
	}
	LA11: ;
	if (c_205061.Errorssaferststringtohtml) nimGCunrefNoCycle(c_205061.Errorssaferststringtohtml);
	c_205061.Errorssaferststringtohtml = (TY117411*) newSeqRC1((&NTI117411), 0);
	LOC16 = 0;
	{
		if (!!(c_205061.Findfilehandler.Field1 == 0)) goto LA19;
		LOC16 = findfilecallbackwrapper_205418;
	}
	goto LA17;
	LA19: ;
	{
		LOC16 = c_205061.Findfilehandler.Field0;
	}
	LA17: ;
	LOC22 = 0;
	{
		if (!!(c_205061.Msghandler.Field1 == 0)) goto LA25;
		LOC22 = msgcallbackwrapper_205085;
	}
	goto LA23;
	LA25: ;
	{
		LOC22 = c_205061.Msghandler.Field0;
	}
	LA23: ;
	asgnRefNoCycle((void**) &c_205061.Retsaferststringtohtml, saferststringtohtml_203277(data, filename, &c_205061.Errorssaferststringtohtml, config, LOC16, LOC22));
	{
		if (!c_205061.Retsaferststringtohtml == 0) goto LA30;
		result = NIM_NIL;
	}
	goto LA28;
	LA30: ;
	{
		result = c_205061.Retsaferststringtohtml->data;
	}
	LA28: ;
	{
		if (!!(errors == 0)) goto LA35;
		(*errors) = ((int) (c_205061.Errorssaferststringtohtml->Sup.len));
	}
	LA35: ;
	return result;
}

N_NIMCALL(NCSTRING, lr_safe_rst_string_to_html_error)(int pos) {
	NCSTRING result;
	result = 0;
	{
		NIM_BOOL LOC3;
		NIM_BOOL LOC4;
		LOC3 = 0;
		LOC4 = 0;
		LOC4 = c_205061.Errorssaferststringtohtml == 0;
		if (LOC4) goto LA5;
		LOC4 = (pos < ((NI32) 0));
		LA5: ;
		LOC3 = LOC4;
		if (LOC3) goto LA6;
		LOC3 = (c_205061.Errorssaferststringtohtml->Sup.len <= ((NI) (pos)));
		LA6: ;
		if (!LOC3) goto LA7;
		goto BeforeRet;
	}
	LA7: ;
	{
		if (!c_205061.Errorssaferststringtohtml->data[pos] == 0) goto LA11;
		result = NIM_NIL;
	}
	goto LA9;
	LA11: ;
	{
		result = c_205061.Errorssaferststringtohtml->data[pos]->data;
	}
	LA9: ;
	BeforeRet: ;
	return result;
}

N_NIMCALL(NCSTRING, lr_safe_rst_file_to_html)(NCSTRING filename_206040, NI32* errors, tstringtable127812* config_206043) {
	NCSTRING result;
	tstringtable127812* config;
	NimStringDesc* filename;
	TY205419 LOC11;
	TY205086 LOC17;
	result = 0;
	{
		if (!(config_206043 == NIM_NIL)) goto LA3;
		config = c_205061.Globaloptions;
	}
	goto LA1;
	LA3: ;
	{
		config = config_206043;
	}
	LA1: ;
	{
		if (!filename_206040 == 0) goto LA8;
		filename = NIM_NIL;
	}
	goto LA6;
	LA8: ;
	{
		filename = cstrToNimstr(filename_206040);
	}
	LA6: ;
	if (c_205061.Errorssaferstfiletohtml) nimGCunrefNoCycle(c_205061.Errorssaferstfiletohtml);
	c_205061.Errorssaferstfiletohtml = (TY117411*) newSeqRC1((&NTI117411), 0);
	LOC11 = 0;
	{
		if (!!(c_205061.Findfilehandler.Field1 == 0)) goto LA14;
		LOC11 = findfilecallbackwrapper_205418;
	}
	goto LA12;
	LA14: ;
	{
		LOC11 = c_205061.Findfilehandler.Field0;
	}
	LA12: ;
	LOC17 = 0;
	{
		if (!!(c_205061.Msghandler.Field1 == 0)) goto LA20;
		LOC17 = msgcallbackwrapper_205085;
	}
	goto LA18;
	LA20: ;
	{
		LOC17 = c_205061.Msghandler.Field0;
	}
	LA18: ;
	asgnRefNoCycle((void**) &c_205061.Retsaferstfiletohtml, saferstfiletohtml_203526(filename, &c_205061.Errorssaferstfiletohtml, config, LOC11, LOC17));
	{
		if (!c_205061.Retsaferstfiletohtml == 0) goto LA25;
		result = NIM_NIL;
	}
	goto LA23;
	LA25: ;
	{
		result = c_205061.Retsaferstfiletohtml->data;
	}
	LA23: ;
	{
		if (!!(errors == 0)) goto LA30;
		(*errors) = ((int) (c_205061.Errorssaferstfiletohtml->Sup.len));
	}
	LA30: ;
	return result;
}

N_NIMCALL(NCSTRING, lr_safe_rst_file_to_html_error)(int pos) {
	NCSTRING result;
	result = 0;
	{
		NIM_BOOL LOC3;
		NIM_BOOL LOC4;
		LOC3 = 0;
		LOC4 = 0;
		LOC4 = c_205061.Errorssaferstfiletohtml == 0;
		if (LOC4) goto LA5;
		LOC4 = (pos < ((NI32) 0));
		LA5: ;
		LOC3 = LOC4;
		if (LOC3) goto LA6;
		LOC3 = (c_205061.Errorssaferstfiletohtml->Sup.len <= ((NI) (pos)));
		LA6: ;
		if (!LOC3) goto LA7;
		goto BeforeRet;
	}
	LA7: ;
	{
		if (!c_205061.Errorssaferstfiletohtml->data[pos] == 0) goto LA11;
		result = NIM_NIL;
	}
	goto LA9;
	LA11: ;
	{
		result = c_205061.Errorssaferstfiletohtml->data[pos]->data;
	}
	LA9: ;
	BeforeRet: ;
	return result;
}

N_NIMCALL(NCSTRING, lr_source_string_to_html)(NCSTRING content_206163, NCSTRING filename_206164, NCSTRING language_206165, int numberlines_206166, tstringtable127812* config_206167) {
	NCSTRING result;
	tstringtable127812* config;
	NimStringDesc* content;
	NimStringDesc* filename;
	NimStringDesc* language;
	NIM_BOOL numberlines;
	result = 0;
	{
		if (!(config_206167 == NIM_NIL)) goto LA3;
		config = c_205061.Globaloptions;
	}
	goto LA1;
	LA3: ;
	{
		config = config_206167;
	}
	LA1: ;
	{
		if (!content_206163 == 0) goto LA8;
		content = NIM_NIL;
	}
	goto LA6;
	LA8: ;
	{
		content = cstrToNimstr(content_206163);
	}
	LA6: ;
	{
		if (!filename_206164 == 0) goto LA13;
		filename = NIM_NIL;
	}
	goto LA11;
	LA13: ;
	{
		filename = cstrToNimstr(filename_206164);
	}
	LA11: ;
	{
		if (!language_206165 == 0) goto LA18;
		language = NIM_NIL;
	}
	goto LA16;
	LA18: ;
	{
		language = cstrToNimstr(language_206165);
	}
	LA16: ;
	{
		if (!!((numberlines_206166 == ((NI32) 0)))) goto LA23;
		numberlines = NIM_TRUE;
	}
	goto LA21;
	LA23: ;
	{
		numberlines = NIM_FALSE;
	}
	LA21: ;
	asgnRefNoCycle((void**) &c_205061.Retsourcestringtohtml, sourcestringtohtml_203593(content, filename, language, numberlines, config));
	{
		if (!c_205061.Retsourcestringtohtml == 0) goto LA28;
		result = NIM_NIL;
	}
	goto LA26;
	LA28: ;
	{
		result = c_205061.Retsourcestringtohtml->data;
	}
	LA26: ;
	return result;
}

N_NIMCALL(NCSTRING, lr_source_file_to_html)(NCSTRING filename_206199, NCSTRING language_206200, int numberlines_206201, tstringtable127812* config_206202) {
	NCSTRING result;
	tstringtable127812* config;
	NimStringDesc* filename;
	NimStringDesc* language;
	NIM_BOOL numberlines;
	result = 0;
	{
		if (!(config_206202 == NIM_NIL)) goto LA3;
		config = c_205061.Globaloptions;
	}
	goto LA1;
	LA3: ;
	{
		config = config_206202;
	}
	LA1: ;
	{
		if (!filename_206199 == 0) goto LA8;
		filename = NIM_NIL;
	}
	goto LA6;
	LA8: ;
	{
		filename = cstrToNimstr(filename_206199);
	}
	LA6: ;
	{
		if (!language_206200 == 0) goto LA13;
		language = NIM_NIL;
	}
	goto LA11;
	LA13: ;
	{
		language = cstrToNimstr(language_206200);
	}
	LA11: ;
	{
		if (!!((numberlines_206201 == ((NI32) 0)))) goto LA18;
		numberlines = NIM_TRUE;
	}
	goto LA16;
	LA18: ;
	{
		numberlines = NIM_FALSE;
	}
	LA16: ;
	asgnRefNoCycle((void**) &c_205061.Retsourcefiletohtml, sourcefiletohtml_203841(filename, language, numberlines, config));
	{
		if (!c_205061.Retsourcefiletohtml == 0) goto LA23;
		result = NIM_NIL;
	}
	goto LA21;
	LA23: ;
	{
		result = c_205061.Retsourcefiletohtml->data;
	}
	LA21: ;
	return result;
}

N_NIMCALL(int, lr_set_normal_error_rst)(NCSTRING inputrst_206233, tstringtable127812* config_206234) {
	int result;
	tstringtable127812* config;
	NimStringDesc* inputrst;
	result = 0;
	{
		if (!(config_206234 == NIM_NIL)) goto LA3;
		config = c_205061.Globaloptions;
	}
	goto LA1;
	LA3: ;
	{
		config = config_206234;
	}
	LA1: ;
	{
		if (!inputrst_206233 == 0) goto LA8;
		inputrst = NIM_NIL;
	}
	goto LA6;
	LA8: ;
	{
		inputrst = cstrToNimstr(inputrst_206233);
	}
	LA6: ;
	asgnRefNoCycle((void**) &c_205061.Retsetnormalerrorrst, setnormalerrorrst_204008(inputrst, config));
	result = ((int) (c_205061.Retsetnormalerrorrst->Sup.len));
	return result;
}

N_NIMCALL(NCSTRING, lr_set_normal_error_rst_error)(int pos) {
	NCSTRING result;
	result = 0;
	{
		NIM_BOOL LOC3;
		NIM_BOOL LOC4;
		LOC3 = 0;
		LOC4 = 0;
		LOC4 = c_205061.Retsetnormalerrorrst == 0;
		if (LOC4) goto LA5;
		LOC4 = (pos < ((NI32) 0));
		LA5: ;
		LOC3 = LOC4;
		if (LOC3) goto LA6;
		LOC3 = (c_205061.Retsetnormalerrorrst->Sup.len <= ((NI) (pos)));
		LA6: ;
		if (!LOC3) goto LA7;
		goto BeforeRet;
	}
	LA7: ;
	{
		if (!c_205061.Retsetnormalerrorrst->data[pos] == 0) goto LA11;
		result = NIM_NIL;
	}
	goto LA9;
	LA11: ;
	{
		result = c_205061.Retsetnormalerrorrst->data[pos]->data;
	}
	LA9: ;
	BeforeRet: ;
	return result;
}

N_NIMCALL(int, lr_set_safe_error_rst)(NCSTRING inputrst_206308, tstringtable127812* config_206309) {
	int result;
	tstringtable127812* config;
	NimStringDesc* inputrst;
	result = 0;
	{
		if (!(config_206309 == NIM_NIL)) goto LA3;
		config = c_205061.Globaloptions;
	}
	goto LA1;
	LA3: ;
	{
		config = config_206309;
	}
	LA1: ;
	{
		if (!inputrst_206308 == 0) goto LA8;
		inputrst = NIM_NIL;
	}
	goto LA6;
	LA8: ;
	{
		inputrst = cstrToNimstr(inputrst_206308);
	}
	LA6: ;
	asgnRefNoCycle((void**) &c_205061.Retsetsafeerrorrst, setsafeerrorrst_204092(inputrst, config));
	result = ((int) (c_205061.Retsetsafeerrorrst->Sup.len));
	return result;
}

N_NIMCALL(NCSTRING, lr_set_safe_error_rst_error)(int pos) {
	NCSTRING result;
	result = 0;
	{
		NIM_BOOL LOC3;
		NIM_BOOL LOC4;
		LOC3 = 0;
		LOC4 = 0;
		LOC4 = c_205061.Retsetsafeerrorrst == 0;
		if (LOC4) goto LA5;
		LOC4 = (pos < ((NI32) 0));
		LA5: ;
		LOC3 = LOC4;
		if (LOC3) goto LA6;
		LOC3 = (c_205061.Retsetsafeerrorrst->Sup.len <= ((NI) (pos)));
		LA6: ;
		if (!LOC3) goto LA7;
		goto BeforeRet;
	}
	LA7: ;
	{
		if (!c_205061.Retsetsafeerrorrst->data[pos] == 0) goto LA11;
		result = NIM_NIL;
	}
	goto LA9;
	LA11: ;
	{
		result = c_205061.Retsetsafeerrorrst->data[pos]->data;
	}
	LA9: ;
	BeforeRet: ;
	return result;
}

static N_INLINE(void, initStackBottomWith)(void* locals) {
	setStackBottom(locals);
}
void PreMainInner() {
	systemInit();
	HEX00_parseutilsDatInit();
	HEX00_strutilsDatInit();
	HEX00_timesDatInit();
	HEX00_posixDatInit();
	HEX00_osDatInit();
	HEX00_hashesDatInit();
	HEX00_strtabsDatInit();
	HEX00_streamsDatInit();
	HEX00_lexbaseDatInit();
	HEX00_unicodeDatInit();
	HEX00_jsonDatInit();
	HEX00_lrstastDatInit();
	HEX00_typetraitsDatInit();
	HEX00_bb_systemDatInit();
	HEX00_parsecfgDatInit();
	HEX00_lconfigDatInit();
	HEX00_lrstDatInit();
	HEX00_lhighliteDatInit();
	HEX00_mathDatInit();
	HEX00_tablesDatInit();
	HEX00_sequtilsDatInit();
	HEX00_algorithmDatInit();
	HEX00_lrstgenDatInit();
	HEX00_subexesDatInit();
	HEX00_cookiesDatInit();
	HEX00_cgiDatInit();
	HEX00_lazy_restDatInit();
	lazy_rest_c_apiDatInit();
	HEX00_parseutilsInit();
	HEX00_strutilsInit();
	HEX00_timesInit();
	HEX00_posixInit();
	HEX00_osInit();
	HEX00_hashesInit();
	HEX00_strtabsInit();
	HEX00_streamsInit();
	HEX00_lexbaseInit();
	HEX00_unicodeInit();
	HEX00_jsonInit();
	HEX00_lrstastInit();
	HEX00_typetraitsInit();
	HEX00_bb_systemInit();
	HEX00_parsecfgInit();
	HEX00_lconfigInit();
	HEX00_lrstInit();
	HEX00_lhighliteInit();
	HEX00_mathInit();
	HEX00_tablesInit();
	HEX00_sequtilsInit();
	HEX00_algorithmInit();
	HEX00_lrstgenInit();
	HEX00_subexesInit();
	HEX00_cookiesInit();
	HEX00_cgiInit();
	HEX00_lazy_restInit();
}

void PreMain() {
	void (*volatile inner)();
	systemDatInit();
	inner = PreMainInner;
	initStackBottomWith((void *)&inner);
	(*inner)();
}

int cmdCount;
char** cmdLine;
char** gEnv;
N_CDECL(void, NimMainInner)(void) {
	lazy_rest_c_apiInit();
}

N_CDECL(void, NimMain)(void) {
	void (*volatile inner)();
	PreMain();
	inner = NimMainInner;
	initStackBottomWith((void *)&inner);
	(*inner)();
}

N_NOINLINE(void, lazy_rest_c_apiInit)(void) {
	c_205061.Msghandler.Field0 = lr_stdout_msg_handler;
	c_205061.Findfilehandler.Field0 = lr_unrestricted_find_file_handler;
	c_205061.Findfilebuffersize = ((int) 255);
}

N_NOINLINE(void, lazy_rest_c_apiDatInit)(void) {
}

