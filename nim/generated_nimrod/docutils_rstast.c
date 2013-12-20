/* Generated by Nimrod Compiler v0.9.3 */
/*   (c) 2012 Andreas Rumpf */
/* The generated code is subject to the original license. */
#define NIM_INTBITS 64
#include "nimbase.h"
typedef struct trstnode111012 trstnode111012;
typedef struct NimStringDesc NimStringDesc;
typedef struct TGenericSeq TGenericSeq;
typedef struct trstnodeseq111010 trstnodeseq111010;
typedef struct TNimType TNimType;
typedef struct TNimNode TNimNode;
typedef struct tcell38448 tcell38448;
typedef struct tcellseq38464 tcellseq38464;
typedef struct tgcheap40416 tgcheap40416;
typedef struct tcellset38460 tcellset38460;
typedef struct tpagedesc38456 tpagedesc38456;
typedef struct tmemregion21810 tmemregion21810;
typedef struct tsmallchunk21038 tsmallchunk21038;
typedef struct tllchunk21804 tllchunk21804;
typedef struct tbigchunk21040 tbigchunk21040;
typedef struct tintset21015 tintset21015;
typedef struct ttrunk21011 ttrunk21011;
typedef struct tavlnode21808 tavlnode21808;
typedef struct tgcstat40414 tgcstat40414;
typedef struct tbasechunk21036 tbasechunk21036;
typedef struct tfreecell21028 tfreecell21028;
struct TGenericSeq {
NI len;
NI reserved;
};
typedef NIM_CHAR TY611[100000001];
struct NimStringDesc {
  TGenericSeq Sup;
TY611 data;
};
struct trstnode111012 {
NU8 Kind;
NimStringDesc* Text;
NI Level;
trstnodeseq111010* Sons;
};
typedef N_NIMCALL_PTR(void, TY889) (void* p, NI op);
struct TNimType {
NI size;
NU8 kind;
NU8 flags;
TNimType* base;
TNimNode* node;
void* finalizer;
TY889 marker;
};
struct TNimNode {
NU8 kind;
NI offset;
TNimType* typ;
NCSTRING name;
NI len;
TNimNode** sons;
};
struct tcell38448 {
NI Refcount;
TNimType* Typ;
};
struct tcellseq38464 {
NI Len;
NI Cap;
tcell38448** D;
};
struct tcellset38460 {
NI Counter;
NI Max;
tpagedesc38456* Head;
tpagedesc38456** Data;
};
typedef tsmallchunk21038* TY21822[512];
typedef ttrunk21011* ttrunkbuckets21013[256];
struct tintset21015 {
ttrunkbuckets21013 Data;
};
struct tmemregion21810 {
NI Minlargeobj;
NI Maxlargeobj;
TY21822 Freesmallchunks;
tllchunk21804* Llmem;
NI Currmem;
NI Maxmem;
NI Freemem;
NI Lastsize;
tbigchunk21040* Freechunkslist;
tintset21015 Chunkstarts;
tavlnode21808* Root;
tavlnode21808* Deleted;
tavlnode21808* Last;
tavlnode21808* Freeavlnodes;
};
struct tgcstat40414 {
NI Stackscans;
NI Cyclecollections;
NI Maxthreshold;
NI Maxstacksize;
NI Maxstackcells;
NI Cycletablesize;
NI64 Maxpause;
};
struct tgcheap40416 {
void* Stackbottom;
NI Cyclethreshold;
tcellseq38464 Zct;
tcellseq38464 Decstack;
tcellset38460 Cycleroots;
tcellseq38464 Tempstack;
NI Recgclock;
tmemregion21810 Region;
tgcstat40414 Stat;
};
typedef NI TY21018[8];
struct tpagedesc38456 {
tpagedesc38456* Next;
NI Key;
TY21018 Bits;
};
struct tbasechunk21036 {
NI Prevsize;
NI Size;
NIM_BOOL Used;
};
struct tsmallchunk21038 {
  tbasechunk21036 Sup;
tsmallchunk21038* Next;
tsmallchunk21038* Prev;
tfreecell21028* Freelist;
NI Free;
NI Acc;
NF Data;
};
struct tllchunk21804 {
NI Size;
NI Acc;
tllchunk21804* Next;
};
struct tbigchunk21040 {
  tbasechunk21036 Sup;
tbigchunk21040* Next;
tbigchunk21040* Prev;
NI Align;
NF Data;
};
struct ttrunk21011 {
ttrunk21011* Next;
NI Key;
TY21018 Bits;
};
typedef tavlnode21808* TY21814[2];
struct tavlnode21808 {
TY21814 Link;
NI Key;
NI Upperbound;
NI Level;
};
struct tfreecell21028 {
tfreecell21028* Next;
NI Zerofield;
};
struct trstnodeseq111010 {
  TGenericSeq Sup;
  trstnode111012* data[SEQ_DECL_SIZE];
};
N_NIMCALL(void, nimGCvisit)(void* d, NI op);
N_NIMCALL(void, TMP113)(void* p, NI op);
N_NIMCALL(void, TMP114)(void* p, NI op);
N_NIMCALL(trstnode111012*, newrstnode_111097)(NU8 kind);
N_NIMCALL(void*, newObj)(TNimType* typ, NI size);
static N_INLINE(void, nimGCunrefNoCycle)(void* p);
static N_INLINE(tcell38448*, usrtocell_41839)(void* usr);
static N_INLINE(void, rtladdzct_43402)(tcell38448* c);
N_NOINLINE(void, addzct_41815)(tcellseq38464* s, tcell38448* c);
N_NIMCALL(void*, newSeqRC1)(TNimType* typ, NI len);
N_NIMCALL(NimStringDesc*, copyStringRC1)(NimStringDesc* src);
N_NIMCALL(TGenericSeq*, incrSeq)(TGenericSeq* seq, NI elemsize);
static N_INLINE(void, asgnRefNoCycle)(void** dest, void* src);
N_NIMCALL(void, add_111153)(trstnode111012* father, trstnode111012* son);
TNimType NTI111012; /* TRSTNode */
TNimType NTI111006; /* TRstNodeKind */
extern TNimType NTI142; /* string */
extern TNimType NTI105; /* int */
TNimType NTI111010; /* TRstNodeSeq */
TNimType NTI111008; /* PRSTNode */
extern tgcheap40416 gch_40444;
N_NIMCALL(void, TMP113)(void* p, NI op) {
	trstnodeseq111010* a;
	NI LOC1;
	a = (trstnodeseq111010*)p;
	LOC1 = 0;
	for (LOC1 = 0; LOC1 < a->Sup.len; LOC1++) {
	nimGCvisit((void*)a->data[LOC1], op);
	}
}
N_NIMCALL(void, TMP114)(void* p, NI op) {
	trstnode111012* a;
	a = (trstnode111012*)p;
	nimGCvisit((void*)(*a).Text, op);
	nimGCvisit((void*)(*a).Sons, op);
}

N_NIMCALL(NI, len_111083)(trstnode111012* n) {
	NI result;
	result = 0;
	result = (*n).Sons->Sup.len;
	return result;
}
static N_INLINE(tcell38448*, usrtocell_41839)(void* usr) {
	tcell38448* result;
	result = 0;
	result = ((tcell38448*) ((NI)((NU64)(((NI) (usr))) - (NU64)(((NI)sizeof(tcell38448))))));
	return result;
}
static N_INLINE(void, rtladdzct_43402)(tcell38448* c) {
	addzct_41815(&gch_40444.Zct, c);}
static N_INLINE(void, nimGCunrefNoCycle)(void* p) {
	tcell38448* c;
	c = usrtocell_41839(p);
	{
		(*c).Refcount -= 8;
		if (!((NU64)((*c).Refcount) < (NU64)(8))) goto LA3;
		rtladdzct_43402(c);	}	LA3: ;
}
N_NIMCALL(trstnode111012*, newrstnode_111097)(NU8 kind) {
	trstnode111012* result;
	result = 0;
	result = (trstnode111012*) newObj((&NTI111008), sizeof(trstnode111012));
	if ((*result).Sons) nimGCunrefNoCycle((*result).Sons);
	(*result).Sons = (trstnodeseq111010*) newSeqRC1((&NTI111010), 0);
	(*result).Kind = kind;
	return result;
}
N_NIMCALL(trstnode111012*, newrstnode_111132)(NU8 kind, NimStringDesc* s) {
	trstnode111012* result;
	NimStringDesc* LOC1;
	result = 0;
	result = newrstnode_111097(kind);
	LOC1 = 0;
	LOC1 = (*result).Text; (*result).Text = copyStringRC1(s);
	if (LOC1) nimGCunrefNoCycle(LOC1);
	return result;
}
static N_INLINE(void, asgnRefNoCycle)(void** dest, void* src) {
	{
		tcell38448* c;
		if (!!((src == NIM_NIL))) goto LA3;
		c = usrtocell_41839(src);
		(*c).Refcount += 8;
	}	LA3: ;
	{
		tcell38448* c;
		if (!!(((*dest) == NIM_NIL))) goto LA7;
		c = usrtocell_41839((*dest));
		{
			(*c).Refcount -= 8;
			if (!((NU64)((*c).Refcount) < (NU64)(8))) goto LA11;
			rtladdzct_43402(c);		}		LA11: ;
	}	LA7: ;
	(*dest) = src;
}
N_NIMCALL(void, add_111153)(trstnode111012* father, trstnode111012* son) {
	(*father).Sons = (trstnodeseq111010*) incrSeq(&((*father).Sons)->Sup, sizeof(trstnode111012*));
	asgnRefNoCycle((void**) &(*father).Sons->data[(*father).Sons->Sup.len-1], son);
}
N_NIMCALL(void, addifnotnil_111173)(trstnode111012* father, trstnode111012* son) {
	{
		if (!!((son == NIM_NIL))) goto LA3;
		add_111153(father, son);	}	LA3: ;
}
N_NIMCALL(trstnode111012*, lastson_111139)(trstnode111012* n) {
	trstnode111012* result;
	result = 0;
	result = (*n).Sons->data[(NI64)((*n).Sons->Sup.len - 1)];
	return result;
}N_NOINLINE(void, docutilsrstastInit)(void) {
}

N_NOINLINE(void, docutilsrstastDatInit)(void) {
static TNimNode* TMP109[4];
static TNimNode* TMP110[65];
NI TMP112;
static char* NIM_CONST TMP111[65] = {
"rnInner", 
"rnHeadline", 
"rnOverline", 
"rnTransition", 
"rnParagraph", 
"rnBulletList", 
"rnBulletItem", 
"rnEnumList", 
"rnEnumItem", 
"rnDefList", 
"rnDefItem", 
"rnDefName", 
"rnDefBody", 
"rnFieldList", 
"rnField", 
"rnFieldName", 
"rnFieldBody", 
"rnOptionList", 
"rnOptionListItem", 
"rnOptionGroup", 
"rnOption", 
"rnOptionString", 
"rnOptionArgument", 
"rnDescription", 
"rnLiteralBlock", 
"rnQuotedLiteralBlock", 
"rnLineBlock", 
"rnLineBlockItem", 
"rnBlockQuote", 
"rnTable", 
"rnGridTable", 
"rnTableRow", 
"rnTableHeaderCell", 
"rnTableDataCell", 
"rnLabel", 
"rnFootnote", 
"rnCitation", 
"rnStandaloneHyperlink", 
"rnHyperlink", 
"rnRef", 
"rnDirective", 
"rnDirArg", 
"rnRaw", 
"rnTitle", 
"rnContents", 
"rnImage", 
"rnFigure", 
"rnCodeBlock", 
"rnRawHtml", 
"rnRawLatex", 
"rnContainer", 
"rnIndex", 
"rnSubstitutionDef", 
"rnGeneralRole", 
"rnSub", 
"rnSup", 
"rnIdx", 
"rnEmphasis", 
"rnStrongEmphasis", 
"rnTripleEmphasis", 
"rnInterpretedText", 
"rnInlineLiteral", 
"rnSubstitutionReferences", 
"rnSmiley", 
"rnLeaf"};
static TNimNode TMP23[71];
NTI111012.size = sizeof(trstnode111012);
NTI111012.kind = 18;
NTI111012.base = 0;
NTI111012.flags = 2;
TMP109[0] = &TMP23[1];
NTI111006.size = sizeof(NU8);
NTI111006.kind = 14;
NTI111006.base = 0;
NTI111006.flags = 3;
for (TMP112 = 0; TMP112 < 65; TMP112++) {
TMP23[TMP112+2].kind = 1;
TMP23[TMP112+2].offset = TMP112;
TMP23[TMP112+2].name = TMP111[TMP112];
TMP110[TMP112] = &TMP23[TMP112+2];
}
TMP23[67].len = 65; TMP23[67].kind = 2; TMP23[67].sons = &TMP110[0];
NTI111006.node = &TMP23[67];
TMP23[1].kind = 1;
TMP23[1].offset = offsetof(trstnode111012, Kind);
TMP23[1].typ = (&NTI111006);
TMP23[1].name = "kind";
TMP109[1] = &TMP23[68];
TMP23[68].kind = 1;
TMP23[68].offset = offsetof(trstnode111012, Text);
TMP23[68].typ = (&NTI142);
TMP23[68].name = "text";
TMP109[2] = &TMP23[69];
TMP23[69].kind = 1;
TMP23[69].offset = offsetof(trstnode111012, Level);
TMP23[69].typ = (&NTI105);
TMP23[69].name = "level";
TMP109[3] = &TMP23[70];
NTI111010.size = sizeof(trstnodeseq111010*);
NTI111010.kind = 24;
NTI111010.base = (&NTI111008);
NTI111010.flags = 2;
NTI111010.marker = TMP113;
TMP23[70].kind = 1;
TMP23[70].offset = offsetof(trstnode111012, Sons);
TMP23[70].typ = (&NTI111010);
TMP23[70].name = "sons";
TMP23[0].len = 4; TMP23[0].kind = 2; TMP23[0].sons = &TMP109[0];
NTI111012.node = &TMP23[0];
NTI111008.size = sizeof(trstnode111012*);
NTI111008.kind = 22;
NTI111008.base = (&NTI111012);
NTI111008.flags = 2;
NTI111008.marker = TMP114;
}

