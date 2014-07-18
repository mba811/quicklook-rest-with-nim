/* Generated by Nimrod Compiler v0.9.5 */
/*   (c) 2014 Andreas Rumpf */
/* The generated code is subject to the original license. */
#define NIM_INTBITS 64
#include "nimbase.h"

#include <string.h>
typedef struct ttable172052 ttable172052;
typedef struct tkeyvaluepairseq172055 tkeyvaluepairseq172055;
typedef struct tkeyvaluepair172058 tkeyvaluepair172058;
typedef struct NimStringDesc NimStringDesc;
typedef struct TGenericSeq TGenericSeq;
typedef struct TNimType TNimType;
typedef struct TNimNode TNimNode;
typedef struct tcell43711 tcell43711;
typedef struct tcellseq43727 tcellseq43727;
typedef struct tgcheap45616 tgcheap45616;
typedef struct tcellset43723 tcellset43723;
typedef struct tpagedesc43719 tpagedesc43719;
typedef struct tmemregion26010 tmemregion26010;
typedef struct tsmallchunk25240 tsmallchunk25240;
typedef struct tllchunk26004 tllchunk26004;
typedef struct tbigchunk25242 tbigchunk25242;
typedef struct tintset25217 tintset25217;
typedef struct ttrunk25213 ttrunk25213;
typedef struct tavlnode26008 tavlnode26008;
typedef struct tgcstat45614 tgcstat45614;
typedef struct tbasechunk25238 tbasechunk25238;
typedef struct tfreecell25230 tfreecell25230;
struct  TGenericSeq  {
NI len;
NI reserved;
};
struct  NimStringDesc  {
  TGenericSeq Sup;
NIM_CHAR data[SEQ_DECL_SIZE];
};
struct tkeyvaluepair172058 {
NU8 Field0;
NimStringDesc* Field1;
NI Field2;
};
struct  ttable172052  {
tkeyvaluepairseq172055* Data;
NI Counter;
};
typedef N_NIMCALL_PTR(void, TY2689) (void* p, NI op);
struct  TNimType  {
NI size;
NU8 kind;
NU8 flags;
TNimType* base;
TNimNode* node;
void* finalizer;
TY2689 marker;
};
struct  TNimNode  {
NU8 kind;
NI offset;
TNimType* typ;
NCSTRING name;
NI len;
TNimNode** sons;
};
struct  tcell43711  {
NI Refcount;
TNimType* Typ;
};
struct  tcellseq43727  {
NI Len;
NI Cap;
tcell43711** D;
};
struct  tcellset43723  {
NI Counter;
NI Max;
tpagedesc43719* Head;
tpagedesc43719** Data;
};
typedef tsmallchunk25240* TY26022[512];
typedef ttrunk25213* ttrunkbuckets25215[256];
struct  tintset25217  {
ttrunkbuckets25215 Data;
};
struct  tmemregion26010  {
NI Minlargeobj;
NI Maxlargeobj;
TY26022 Freesmallchunks;
tllchunk26004* Llmem;
NI Currmem;
NI Maxmem;
NI Freemem;
NI Lastsize;
tbigchunk25242* Freechunkslist;
tintset25217 Chunkstarts;
tavlnode26008* Root;
tavlnode26008* Deleted;
tavlnode26008* Last;
tavlnode26008* Freeavlnodes;
};
struct  tgcstat45614  {
NI Stackscans;
NI Cyclecollections;
NI Maxthreshold;
NI Maxstacksize;
NI Maxstackcells;
NI Cycletablesize;
NI64 Maxpause;
};
struct  tgcheap45616  {
void* Stackbottom;
NI Cyclethreshold;
tcellseq43727 Zct;
tcellseq43727 Decstack;
tcellset43723 Cycleroots;
tcellseq43727 Tempstack;
NI Recgclock;
tmemregion26010 Region;
tgcstat45614 Stat;
};
typedef NI TY25220[8];
struct  tpagedesc43719  {
tpagedesc43719* Next;
NI Key;
TY25220 Bits;
};
struct  tbasechunk25238  {
NI Prevsize;
NI Size;
NIM_BOOL Used;
};
struct  tsmallchunk25240  {
  tbasechunk25238 Sup;
tsmallchunk25240* Next;
tsmallchunk25240* Prev;
tfreecell25230* Freelist;
NI Free;
NI Acc;
NF Data;
};
struct  tllchunk26004  {
NI Size;
NI Acc;
tllchunk26004* Next;
};
struct  tbigchunk25242  {
  tbasechunk25238 Sup;
tbigchunk25242* Next;
tbigchunk25242* Prev;
NI Align;
NF Data;
};
struct  ttrunk25213  {
ttrunk25213* Next;
NI Key;
TY25220 Bits;
};
typedef tavlnode26008* TY26014[2];
struct  tavlnode26008  {
TY26014 Link;
NI Key;
NI Upperbound;
NI Level;
};
struct  tfreecell25230  {
tfreecell25230* Next;
NI Zerofield;
};
struct tkeyvaluepairseq172055 {
  TGenericSeq Sup;
  tkeyvaluepair172058 data[SEQ_DECL_SIZE];
};
N_NIMCALL(void, nimGCvisit)(void* d, NI op);
N_NIMCALL(void, TMP143)(void* p, NI op);
N_NIMCALL(void*, newSeq)(TNimType* typ, NI len);
N_NIMCALL(void, unsureAsgnRef)(void** dest, void* src);
N_NIMCALL(NI, rawget_172886)(ttable172052 t_172893, NimStringDesc* key_172896);
N_NIMCALL(NI, hash_120842)(NimStringDesc* x);
static N_INLINE(NIM_BOOL, eqStrings)(NimStringDesc* a, NimStringDesc* b);
static N_INLINE(NI, nexttry_164609)(NI h, NI maxhash);
static N_INLINE(NIM_BOOL, mustrehash_164428)(NI length, NI counter);
N_NIMCALL(void, enlarge_173007)(ttable172052* t_173016);
N_NIMCALL(void, rawinsert_173077)(ttable172052* t_173086, tkeyvaluepairseq172055** data_173094, NimStringDesc* key_173098, NI val_173100);
N_NIMCALL(NimStringDesc*, copyStringRC1)(NimStringDesc* src);
static N_INLINE(void, nimGCunrefNoCycle)(void* p);
static N_INLINE(tcell43711*, usrtocell_47246)(void* usr);
static N_INLINE(void, rtladdzct_48804)(tcell43711* c);
N_NOINLINE(void, addzct_47217)(tcellseq43727* s, tcell43711* c);
TNimType NTI172052; /* TTable */
TNimType NTI172058; /* TKeyValuePair */
TNimType NTI164009; /* TSlotEnum */
extern TNimType NTI157; /* string */
extern TNimType NTI112; /* int */
TNimType NTI172055; /* TKeyValuePairSeq */
extern tgcheap45616 gch_45644;
N_NIMCALL(void, TMP143)(void* p, NI op) {
	tkeyvaluepairseq172055* a;
	NI LOC1;
	a = (tkeyvaluepairseq172055*)p;
	LOC1 = 0;
	for (LOC1 = 0; LOC1 < a->Sup.len; LOC1++) {
	nimGCvisit((void*)a->data[LOC1].Field1, op);
	}
}

N_NIMCALL(void, inittable_172108)(NI initialsize_172113, ttable172052* Result) {
	(*Result).Counter = 0;
	unsureAsgnRef((void**) &(*Result).Data, (tkeyvaluepairseq172055*) newSeq((&NTI172055), initialsize_172113));
}

static N_INLINE(NIM_BOOL, eqStrings)(NimStringDesc* a, NimStringDesc* b) {
	NIM_BOOL result;
	NIM_BOOL LOC11;
	int LOC13;
	result = 0;
	{
		if (!(a == b)) goto LA3;
		result = NIM_TRUE;
		goto BeforeRet;
	}
	LA3: ;
	{
		NIM_BOOL LOC7;
		LOC7 = 0;
		LOC7 = (a == NIM_NIL);
		if (LOC7) goto LA8;
		LOC7 = (b == NIM_NIL);
		LA8: ;
		if (!LOC7) goto LA9;
		result = NIM_FALSE;
		goto BeforeRet;
	}
	LA9: ;
	LOC11 = 0;
	LOC11 = ((*a).Sup.len == (*b).Sup.len);
	if (!(LOC11)) goto LA12;
	LOC13 = 0;
	LOC13 = memcmp(((NCSTRING) ((*a).data)), ((NCSTRING) ((*b).data)), (NI64)((*a).Sup.len * 1));
	LOC11 = (LOC13 == ((NI32) 0));
	LA12: ;
	result = LOC11;
	goto BeforeRet;
	BeforeRet: ;
	return result;
}

static N_INLINE(NI, nexttry_164609)(NI h, NI maxhash) {
	NI result;
	result = 0;
	result = (NI)((NI64)((NI64)(5 * h) + 1) & maxhash);
	return result;
}

N_NIMCALL(NI, rawget_172886)(ttable172052 t_172893, NimStringDesc* key_172896) {
	NI result;
	NI h;
	NI LOC1;
	result = 0;
	LOC1 = 0;
	LOC1 = hash_120842(key_172896);
	h = (NI)(LOC1 & (t_172893.Data->Sup.len-1));
	while (1) {
		if (!!((t_172893.Data->data[h].Field0 == ((NU8) 0)))) goto LA2;
		{
			NIM_BOOL LOC5;
			LOC5 = 0;
			LOC5 = eqStrings(t_172893.Data->data[h].Field1, key_172896);
			if (!(LOC5)) goto LA6;
			LOC5 = (t_172893.Data->data[h].Field0 == ((NU8) 1));
			LA6: ;
			if (!LOC5) goto LA7;
			result = h;
			goto BeforeRet;
		}
		LA7: ;
		h = nexttry_164609(h, (t_172893.Data->Sup.len-1));
	} LA2: ;
	result = -1;
	BeforeRet: ;
	return result;
}

N_NIMCALL(NIM_BOOL, haskey_172872)(ttable172052 t_172879, NimStringDesc* key_172882) {
	NIM_BOOL result;
	NI LOC1;
	result = 0;
	LOC1 = 0;
	LOC1 = rawget_172886(t_172879, key_172882);
	result = (0 <= LOC1);
	return result;
}

static N_INLINE(NIM_BOOL, mustrehash_164428)(NI length, NI counter) {
	NIM_BOOL result;
	NIM_BOOL LOC1;
	result = 0;
	LOC1 = 0;
	LOC1 = ((NI64)(length * 2) < (NI64)(counter * 3));
	if (LOC1) goto LA2;
	LOC1 = ((NI64)(length - counter) < 4);
	LA2: ;
	result = LOC1;
	return result;
}

static N_INLINE(tcell43711*, usrtocell_47246)(void* usr) {
	tcell43711* result;
	result = 0;
	result = ((tcell43711*) ((NI)((NU64)(((NI) (usr))) - (NU64)(((NI)sizeof(tcell43711))))));
	return result;
}

static N_INLINE(void, rtladdzct_48804)(tcell43711* c) {
	addzct_47217(&gch_45644.Zct, c);
}

static N_INLINE(void, nimGCunrefNoCycle)(void* p) {
	tcell43711* c;
	c = usrtocell_47246(p);
	{
		(*c).Refcount -= 8;
		if (!((NU64)((*c).Refcount) < (NU64)(8))) goto LA3;
		rtladdzct_48804(c);
	}
	LA3: ;
}

N_NIMCALL(void, rawinsert_173077)(ttable172052* t_173086, tkeyvaluepairseq172055** data_173094, NimStringDesc* key_173098, NI val_173100) {
	NI h;
	NI LOC1;
	NimStringDesc* LOC3;
	LOC1 = 0;
	LOC1 = hash_120842(key_173098);
	h = (NI)(LOC1 & ((*data_173094)->Sup.len-1));
	while (1) {
		if (!((*data_173094)->data[h].Field0 == ((NU8) 1))) goto LA2;
		h = nexttry_164609(h, ((*data_173094)->Sup.len-1));
	} LA2: ;
	LOC3 = 0;
	LOC3 = (*data_173094)->data[h].Field1; (*data_173094)->data[h].Field1 = copyStringRC1(key_173098);
	if (LOC3) nimGCunrefNoCycle(LOC3);
	(*data_173094)->data[h].Field2 = val_173100;
	(*data_173094)->data[h].Field0 = ((NU8) 1);
}

N_NIMCALL(void, enlarge_173007)(ttable172052* t_173016) {
	tkeyvaluepairseq172055* n;
	NI i_173062;
	NI HEX3Atmp_173136;
	NI res_173138;
	tkeyvaluepairseq172055* LOC6;
	n = 0;
	n = (tkeyvaluepairseq172055*) newSeq((&NTI172055), (NI64)((*t_173016).Data->Sup.len * 2));
	i_173062 = 0;
	HEX3Atmp_173136 = 0;
	HEX3Atmp_173136 = ((*t_173016).Data->Sup.len-1);
	res_173138 = 0;
	while (1) {
		if (!(res_173138 <= HEX3Atmp_173136)) goto LA1;
		i_173062 = res_173138;
		{
			if (!((*t_173016).Data->data[i_173062].Field0 == ((NU8) 1))) goto LA4;
			rawinsert_173077(t_173016, &n, (*t_173016).Data->data[i_173062].Field1, (*t_173016).Data->data[i_173062].Field2);
		}
		LA4: ;
		res_173138 += 1;
	} LA1: ;
	LOC6 = 0;
	LOC6 = (*t_173016).Data;
	unsureAsgnRef((void**) &(*t_173016).Data, n);
	n = LOC6;
}

N_NIMCALL(void, HEX5BHEX5DHEX3D_172962)(ttable172052* t_172971, NimStringDesc* key_172975, NI val_172977) {
	NI index;
	index = rawget_172886((*t_172971), key_172975);
	{
		if (!(0 <= index)) goto LA3;
		(*t_172971).Data->data[index].Field2 = val_172977;
	}
	goto LA1;
	LA3: ;
	{
		{
			NIM_BOOL LOC8;
			LOC8 = 0;
			LOC8 = mustrehash_164428((*t_172971).Data->Sup.len, (*t_172971).Counter);
			if (!LOC8) goto LA9;
			enlarge_173007(t_172971);
		}
		LA9: ;
		rawinsert_173077(t_172971, &(*t_172971).Data, key_172975, val_172977);
		(*t_172971).Counter += 1;
	}
	LA1: ;
}

N_NIMCALL(NI, HEX5BHEX5D_172931)(ttable172052 t_172938, NimStringDesc* key_172941) {
	NI result;
	NI index;
	result = 0;
	index = rawget_172886(t_172938, key_172941);
	{
		if (!(0 <= index)) goto LA3;
		result = t_172938.Data->data[index].Field2;
	}
	LA3: ;
	return result;
}
N_NOINLINE(void, stdlib_tablesInit)(void) {
}

N_NOINLINE(void, stdlib_tablesDatInit)(void) {
static TNimNode* TMP138[2];
static TNimNode* TMP139[3];
static TNimNode* TMP140[3];
NI TMP142;
static char* NIM_CONST TMP141[3] = {
"seEmpty", 
"seFilled", 
"seDeleted"};
static TNimNode TMP37[11];
NTI172052.size = sizeof(ttable172052);
NTI172052.kind = 18;
NTI172052.base = 0;
NTI172052.flags = 2;
TMP138[0] = &TMP37[1];
NTI172058.size = sizeof(tkeyvaluepair172058);
NTI172058.kind = 18;
NTI172058.base = 0;
NTI172058.flags = 2;
TMP139[0] = &TMP37[3];
NTI164009.size = sizeof(NU8);
NTI164009.kind = 14;
NTI164009.base = 0;
NTI164009.flags = 3;
for (TMP142 = 0; TMP142 < 3; TMP142++) {
TMP37[TMP142+4].kind = 1;
TMP37[TMP142+4].offset = TMP142;
TMP37[TMP142+4].name = TMP141[TMP142];
TMP140[TMP142] = &TMP37[TMP142+4];
}
TMP37[7].len = 3; TMP37[7].kind = 2; TMP37[7].sons = &TMP140[0];
NTI164009.node = &TMP37[7];
TMP37[3].kind = 1;
TMP37[3].offset = offsetof(tkeyvaluepair172058, Field0);
TMP37[3].typ = (&NTI164009);
TMP37[3].name = "Field0";
TMP139[1] = &TMP37[8];
TMP37[8].kind = 1;
TMP37[8].offset = offsetof(tkeyvaluepair172058, Field1);
TMP37[8].typ = (&NTI157);
TMP37[8].name = "Field1";
TMP139[2] = &TMP37[9];
TMP37[9].kind = 1;
TMP37[9].offset = offsetof(tkeyvaluepair172058, Field2);
TMP37[9].typ = (&NTI112);
TMP37[9].name = "Field2";
TMP37[2].len = 3; TMP37[2].kind = 2; TMP37[2].sons = &TMP139[0];
NTI172058.node = &TMP37[2];
NTI172055.size = sizeof(tkeyvaluepairseq172055*);
NTI172055.kind = 24;
NTI172055.base = (&NTI172058);
NTI172055.flags = 2;
NTI172055.marker = TMP143;
TMP37[1].kind = 1;
TMP37[1].offset = offsetof(ttable172052, Data);
TMP37[1].typ = (&NTI172055);
TMP37[1].name = "data";
TMP138[1] = &TMP37[10];
TMP37[10].kind = 1;
TMP37[10].offset = offsetof(ttable172052, Counter);
TMP37[10].typ = (&NTI112);
TMP37[10].name = "counter";
TMP37[0].len = 2; TMP37[0].kind = 2; TMP37[0].sons = &TMP138[0];
NTI172052.node = &TMP37[0];
}
