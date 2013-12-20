/* Generated by Nimrod Compiler v0.9.3 */
/*   (c) 2012 Andreas Rumpf */
/* The generated code is subject to the original license. */
#define NIM_INTBITS 64
#include "nimbase.h"

#include <stdlib.h>

#include <sys/param.h>

#include <mach-o/dyld.h>

#include <string.h>

#include <errno.h>

#include <sys/stat.h>

#include <sys/types.h>

#include <sys/time.h>
typedef struct TY101828 TY101828;
typedef struct NimStringDesc NimStringDesc;
typedef struct TGenericSeq TGenericSeq;
typedef struct eos1035 eos1035;
typedef struct esystem1031 esystem1031;
typedef struct esynch1029 esynch1029;
typedef struct E_Base E_Base;
typedef struct TNimObject TNimObject;
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
typedef struct TY100259 TY100259;
typedef struct TY86506 TY86506;
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
struct TNimObject {
TNimType* m_type;
};
struct E_Base {
  TNimObject Sup;
E_Base* parent;
NCSTRING name;
NimStringDesc* message;
NimStringDesc* trace;
};
struct esynch1029 {
  E_Base Sup;
};
struct esystem1031 {
  esynch1029 Sup;
};
struct eos1035 {
  esystem1031 Sup;
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
struct TY100259 {
NimStringDesc* Field0;
NimStringDesc* Field1;
NimStringDesc* Field2;
};
struct TY86506 {
NimStringDesc* Field0;
NimStringDesc* Field1;
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
struct TY101828 {
  TGenericSeq Sup;
  NimStringDesc* data[SEQ_DECL_SIZE];
};
N_NIMCALL(NimStringDesc*, mnewString)(NI len);
N_NIMCALL(NimStringDesc*, mnewString)(NI len);
N_NIMCALL(NimStringDesc*, copyString)(NimStringDesc* src);
N_NIMCALL(NimStringDesc*, nosexpandFilename)(NimStringDesc* filename);
N_NIMCALL(void, oserror_98005)(NI32 errorcode);
N_NIMCALL(NimStringDesc*, oserrormsg_97858)(NI32 errorcode);
N_NIMCALL(NimStringDesc*, cstrToNimstr)(NCSTRING str);
N_NIMCALL(void*, newObj)(TNimType* typ, NI size);
N_NIMCALL(NimStringDesc*, copyStringRC1)(NimStringDesc* src);
static N_INLINE(void, nimGCunrefNoCycle)(void* p);
static N_INLINE(tcell38448*, usrtocell_41839)(void* usr);
static N_INLINE(void, rtladdzct_43402)(tcell38448* c);
N_NOINLINE(void, addzct_41815)(tcellseq38464* s, tcell38448* c);
N_NIMCALL(void, raiseException)(E_Base* e, NCSTRING ename);
N_NIMCALL(NI32, oslasterror_98046)(void);
N_NIMCALL(NimStringDesc*, setLengthStr)(NimStringDesc* s, NI newlen);
N_NIMCALL(void, unsureAsgnRef)(void** dest, void* src);
N_NIMCALL(NimStringDesc*, copyStrLast)(NimStringDesc* s, NI start_67023, NI last);
N_NIMCALL(NimStringDesc*, copyStrLast)(NimStringDesc* s, NI first, NI last);
N_NIMCALL(NimStringDesc*, copyStr)(NimStringDesc* s, NI start);
N_NIMCALL(NimStringDesc*, copyStr)(NimStringDesc* s, NI first);
N_NIMCALL(NimStringDesc*, nosJoinPath)(NimStringDesc* head, NimStringDesc* tail);
static N_INLINE(void, appendString)(NimStringDesc* dest, NimStringDesc* src);
N_NIMCALL(NimStringDesc*, rawNewString)(NI space);
static N_INLINE(void, appendChar)(NimStringDesc* dest, NIM_CHAR c);
N_NIMCALL(NI, findenvvar_102403)(NimStringDesc* key);
N_NIMCALL(void, getenvvarsc_102002)(void);
N_NIMCALL(void, nimGCvisit)(void* d, NI op);
N_NIMCALL(void, TMP200)(void* p, NI op);
N_NIMCALL(void*, newSeqRC1)(TNimType* typ, NI len);
N_NIMCALL(TGenericSeq*, incrSeq)(TGenericSeq* seq, NI elemsize);
N_NIMCALL(NIM_BOOL, nsuStartsWith)(NimStringDesc* s, NimStringDesc* prefix);
N_NIMCALL(NI, nsuFindChar)(NimStringDesc* s, NIM_CHAR sub, NI start);
N_NIMCALL(NI, searchextpos_100226)(NimStringDesc* s);
N_NIMCALL(NimStringDesc*, normext_100220)(NimStringDesc* ext);
N_NIMCALL(void, nosSplitPath)(NimStringDesc* path, TY86506* Result);
STRING_LITERAL(TMP58, "", 0);
STRING_LITERAL(TMP60, "unknown OS error", 16);
NIM_BOOL envcomputed_101827;
TY101828* environment_101829;
extern NCSTRING* environ;
extern int cmdCount;
extern NCSTRING* cmdLine;
extern TNimType NTI98012; /* ref EOS */
extern TNimType NTI1035; /* EOS */
extern tgcheap40416 gch_40444;
extern TNimType NTI142; /* string */
TNimType NTI101828; /* seq[string] */

N_NIMCALL(NimStringDesc*, oserrormsg_97858)(NI32 errorcode) {
	NimStringDesc* result;
	result = 0;
	result = copyString(((NimStringDesc*) &TMP58));
	{
		NCSTRING LOC5;
		if (!!((errorcode == ((NI32) 0)))) goto LA3;
		LOC5 = 0;
		LOC5 = strerror(errorcode);
		result = cstrToNimstr(LOC5);
	}	LA3: ;
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
N_NIMCALL(void, oserror_98005)(NI32 errorcode) {
	NimStringDesc* msg;
	msg = oserrormsg_97858(errorcode);
	{
		eos1035* e_98011;
		NimStringDesc* LOC5;
		if (!((msg) && (msg)->Sup.len == 0)) goto LA3;
		e_98011 = 0;
		e_98011 = (eos1035*) newObj((&NTI98012), sizeof(eos1035));
		(*e_98011).Sup.Sup.Sup.Sup.m_type = (&NTI1035);
		LOC5 = 0;
		LOC5 = (*e_98011).Sup.Sup.Sup.message; (*e_98011).Sup.Sup.Sup.message = copyStringRC1(((NimStringDesc*) &TMP60));
		if (LOC5) nimGCunrefNoCycle(LOC5);
		raiseException((E_Base*)e_98011, "EOS");
	}	goto LA1;
	LA3: ;
	{
		eos1035* e_98027;
		NimStringDesc* LOC7;
		e_98027 = 0;
		e_98027 = (eos1035*) newObj((&NTI98012), sizeof(eos1035));
		(*e_98027).Sup.Sup.Sup.Sup.m_type = (&NTI1035);
		LOC7 = 0;
		LOC7 = (*e_98027).Sup.Sup.Sup.message; (*e_98027).Sup.Sup.Sup.message = copyStringRC1(msg);
		if (LOC7) nimGCunrefNoCycle(LOC7);
		raiseException((E_Base*)e_98027, "EOS");
	}	LA1: ;
}
N_NIMCALL(NI32, oslasterror_98046)(void) {
	NI32 result;
	result = 0;
	result = errno;
	return result;
}
N_NIMCALL(NimStringDesc*, nosexpandFilename)(NimStringDesc* filename) {
	NimStringDesc* result;
	NCSTRING r;
	NI LOC6;
	result = 0;
	result = mnewString(((NI) (PATH_MAX)));
	r = realpath(filename->data, result->data);
	{
		NI32 LOC5;
		if (!r == 0) goto LA3;
		LOC5 = 0;
		LOC5 = oslasterror_98046();
		oserror_98005(LOC5);	}	LA3: ;
	LOC6 = 0;
	LOC6 = strlen(result->data);
	result = setLengthStr(result, LOC6);
	return result;
}
N_NIMCALL(NimStringDesc*, nosgetAppFilename)(void) {
	NimStringDesc* result;
	unsigned int size;
	result = 0;
	size = 0;
	_NSGetExecutablePath(NIM_NIL, &size);	result = mnewString(size);
	{
		NIM_BOOL LOC3;
		LOC3 = 0;
		LOC3 = _NSGetExecutablePath(result->data, &size);
		if (!LOC3) goto LA4;
		result = copyString(((NimStringDesc*) &TMP58));
	}	LA4: ;
	{
		if (!(0 < result->Sup.len)) goto LA8;
		result = nosexpandFilename(result);
	}	LA8: ;
	return result;
}
N_NIMCALL(void, nossplitFile)(NimStringDesc* path, TY100259* Result) {
	{
		NIM_BOOL LOC3;
		LOC3 = 0;
		LOC3 = (path->Sup.len == 0);
		if (LOC3) goto LA4;
		LOC3 = (((NU8)(path->data[(NI64)(path->Sup.len - 1)])) == ((NU8)(47)) || ((NU8)(path->data[(NI64)(path->Sup.len - 1)])) == ((NU8)(47)));
		LA4: ;
		if (!LOC3) goto LA5;
		unsureAsgnRef((void**) &(*Result).Field0, copyString(path));
		unsureAsgnRef((void**) &(*Result).Field1, copyString(((NimStringDesc*) &TMP58)));
		unsureAsgnRef((void**) &(*Result).Field2, copyString(((NimStringDesc*) &TMP58)));
	}	goto LA1;
	LA5: ;
	{
		NI seppos;
		NI dotpos;
		NI i_100286;
		NI HEX3Atmp_100310;
		NI res_100312;
		seppos = -1;
		dotpos = path->Sup.len;
		i_100286 = 0;
		HEX3Atmp_100310 = 0;
		HEX3Atmp_100310 = (NI64)(path->Sup.len - 1);
		res_100312 = HEX3Atmp_100310;
		while (1) {
			if (!(0 <= res_100312)) goto LA8;
			i_100286 = res_100312;
			{
				if (!((NU8)(path->data[i_100286]) == (NU8)(46))) goto LA11;
				{
					NIM_BOOL LOC15;
					NIM_BOOL LOC16;
					LOC15 = 0;
					LOC16 = 0;
					LOC16 = (dotpos == path->Sup.len);
					if (!(LOC16)) goto LA17;
					LOC16 = (0 < i_100286);
					LA17: ;
					LOC15 = LOC16;
					if (!(LOC15)) goto LA18;
					LOC15 = !((((NU8)(path->data[(NI64)(i_100286 - 1)])) == ((NU8)(47)) || ((NU8)(path->data[(NI64)(i_100286 - 1)])) == ((NU8)(47))));
					LA18: ;
					if (!LOC15) goto LA19;
					dotpos = i_100286;
				}				LA19: ;
			}			goto LA9;
			LA11: ;
			{
				if (!(((NU8)(path->data[i_100286])) == ((NU8)(47)) || ((NU8)(path->data[i_100286])) == ((NU8)(47)))) goto LA22;
				seppos = i_100286;
				goto LA8;
			}			goto LA9;
			LA22: ;
			LA9: ;
			res_100312 -= 1;
		} LA8: ;
		unsureAsgnRef((void**) &(*Result).Field0, copyStrLast(path, 0, (NI64)(seppos - 1)));
		unsureAsgnRef((void**) &(*Result).Field1, copyStrLast(path, (NI64)(seppos + 1), (NI64)(dotpos - 1)));
		unsureAsgnRef((void**) &(*Result).Field2, copyStr(path, dotpos));
	}	LA1: ;
}
N_NIMCALL(void, nosSplitPath)(NimStringDesc* path, TY86506* Result) {
	NI seppos;
	NI i_100092;
	NI HEX3Atmp_100104;
	NI res_100106;
	seppos = -1;
	i_100092 = 0;
	HEX3Atmp_100104 = 0;
	HEX3Atmp_100104 = (NI64)(path->Sup.len - 1);
	res_100106 = HEX3Atmp_100104;
	while (1) {
		if (!(0 <= res_100106)) goto LA1;
		i_100092 = res_100106;
		{
			if (!(((NU8)(path->data[i_100092])) == ((NU8)(47)) || ((NU8)(path->data[i_100092])) == ((NU8)(47)))) goto LA4;
			seppos = i_100092;
			goto LA1;
		}		LA4: ;
		res_100106 -= 1;
	} LA1: ;
	{
		if (!(0 <= seppos)) goto LA8;
		unsureAsgnRef((void**) &(*Result).Field0, copyStrLast(path, 0, (NI64)(seppos - 1)));
		unsureAsgnRef((void**) &(*Result).Field1, copyStr(path, (NI64)(seppos + 1)));
	}	goto LA6;
	LA8: ;
	{
		unsureAsgnRef((void**) &(*Result).Field0, copyString(((NimStringDesc*) &TMP58)));
		unsureAsgnRef((void**) &(*Result).Field1, copyString(path));
	}	LA6: ;
}
static N_INLINE(void, appendString)(NimStringDesc* dest, NimStringDesc* src) {
	memcpy(((NCSTRING) (&(*dest).data[((*dest).Sup.len)- 0])), ((NCSTRING) ((*src).data)), (NI64)((*src).Sup.len + 1));	(*dest).Sup.len += (*src).Sup.len;
}
static N_INLINE(void, appendChar)(NimStringDesc* dest, NIM_CHAR c) {
	(*dest).data[((*dest).Sup.len)- 0] = c;
	(*dest).data[((NI64)((*dest).Sup.len + 1))- 0] = 0;
	(*dest).Sup.len += 1;
}
N_NIMCALL(NimStringDesc*, nosJoinPath)(NimStringDesc* head, NimStringDesc* tail) {
	NimStringDesc* result;
	result = 0;
	{
		if (!(head->Sup.len == 0)) goto LA3;
		result = copyString(tail);
	}	goto LA1;
	LA3: ;
	{
		if (!(((NU8)(head->data[(NI64)(head->Sup.len - 1)])) == ((NU8)(47)) || ((NU8)(head->data[(NI64)(head->Sup.len - 1)])) == ((NU8)(47)))) goto LA6;
		{
			NimStringDesc* LOC12;
			NimStringDesc* LOC13;
			if (!(((NU8)(tail->data[0])) == ((NU8)(47)) || ((NU8)(tail->data[0])) == ((NU8)(47)))) goto LA10;
			LOC12 = 0;
			LOC13 = 0;
			LOC13 = copyStr(tail, 1);
			LOC12 = rawNewString(head->Sup.len + LOC13->Sup.len + 0);
appendString(LOC12, head);
appendString(LOC12, LOC13);
			result = LOC12;
		}		goto LA8;
		LA10: ;
		{
			NimStringDesc* LOC15;
			LOC15 = 0;
			LOC15 = rawNewString(head->Sup.len + tail->Sup.len + 0);
appendString(LOC15, head);
appendString(LOC15, tail);
			result = LOC15;
		}		LA8: ;
	}	goto LA1;
	LA6: ;
	{
		{
			NimStringDesc* LOC21;
			if (!(((NU8)(tail->data[0])) == ((NU8)(47)) || ((NU8)(tail->data[0])) == ((NU8)(47)))) goto LA19;
			LOC21 = 0;
			LOC21 = rawNewString(head->Sup.len + tail->Sup.len + 0);
appendString(LOC21, head);
appendString(LOC21, tail);
			result = LOC21;
		}		goto LA17;
		LA19: ;
		{
			NimStringDesc* LOC23;
			LOC23 = 0;
			LOC23 = rawNewString(head->Sup.len + tail->Sup.len + 1);
appendString(LOC23, head);
appendChar(LOC23, 47);
appendString(LOC23, tail);
			result = LOC23;
		}		LA17: ;
	}	LA1: ;
	return result;
}
N_NIMCALL(NimStringDesc*, HEX2F_100067)(NimStringDesc* head, NimStringDesc* tail) {
	NimStringDesc* result;
	result = 0;
	result = nosJoinPath(head, tail);
	goto BeforeRet;
	BeforeRet: ;	return result;
}
N_NIMCALL(NIM_BOOL, nosexistsFile)(NimStringDesc* filename) {
	NIM_BOOL result;
	struct stat res;
	NIM_BOOL LOC1;
	int LOC2;
	result = 0;
	memset((void*)&res, 0, sizeof(res));
	LOC1 = 0;
	LOC2 = 0;
	LOC2 = stat(filename->data, &res);
	LOC1 = (((NI32) 0) <= LOC2);
	if (!(LOC1)) goto LA3;
	LOC1 = S_ISREG(res.st_mode);
	LA3: ;
	result = LOC1;
	goto BeforeRet;
	BeforeRet: ;	return result;
}N_NIMCALL(void, TMP200)(void* p, NI op) {
	TY101828* a;
	NI LOC1;
	a = (TY101828*)p;
	LOC1 = 0;
	for (LOC1 = 0; LOC1 < a->Sup.len; LOC1++) {
	nimGCvisit((void*)a->data[LOC1], op);
	}
}

N_NIMCALL(void, getenvvarsc_102002)(void) {
	{
		NI i;
		if (!!(envcomputed_101827)) goto LA3;
		if (environment_101829) nimGCunrefNoCycle(environment_101829);
		environment_101829 = (TY101828*) newSeqRC1((&NTI101828), 0);
		i = 0;
		while (1) {
			NimStringDesc* LOC10;
			NimStringDesc* LOC11;
			{
				if (!(environ[(i)- 0] == NIM_NIL)) goto LA8;
				goto LA5;
			}			LA8: ;
			LOC10 = 0;
			LOC10 = cstrToNimstr(environ[(i)- 0]);
			environment_101829 = (TY101828*) incrSeq(&(environment_101829)->Sup, sizeof(NimStringDesc*));
			LOC11 = 0;
			LOC11 = environment_101829->data[environment_101829->Sup.len-1]; environment_101829->data[environment_101829->Sup.len-1] = copyStringRC1(LOC10);
			if (LOC11) nimGCunrefNoCycle(LOC11);
			i += 1;
		} LA5: ;
		envcomputed_101827 = NIM_TRUE;
	}	LA3: ;
}
N_NIMCALL(NI, findenvvar_102403)(NimStringDesc* key) {
	NI result;
	NimStringDesc* temp;
	NimStringDesc* LOC1;
	NI i_102417;
	NI HEX3Atmp_102418;
	NI res_102420;
	result = 0;
	getenvvarsc_102002();	LOC1 = 0;
	LOC1 = rawNewString(key->Sup.len + 1);
appendString(LOC1, key);
appendChar(LOC1, 61);
	temp = LOC1;
	i_102417 = 0;
	HEX3Atmp_102418 = 0;
	HEX3Atmp_102418 = (environment_101829->Sup.len-1);
	res_102420 = 0;
	while (1) {
		if (!(res_102420 <= HEX3Atmp_102418)) goto LA2;
		i_102417 = res_102420;
		{
			NIM_BOOL LOC5;
			LOC5 = 0;
			LOC5 = nsuStartsWith(environment_101829->data[i_102417], temp);
			if (!LOC5) goto LA6;
			result = i_102417;
			goto BeforeRet;
		}		LA6: ;
		res_102420 += 1;
	} LA2: ;
	result = -1;
	goto BeforeRet;
	BeforeRet: ;	return result;
}
N_NIMCALL(NimStringDesc*, getenv_102425)(NimStringDesc* key) {
	NimStringDesc* result;
	NI i;
	result = 0;
	i = findenvvar_102403(key);
	{
		NI LOC5;
		if (!(0 <= i)) goto LA3;
		LOC5 = 0;
		LOC5 = nsuFindChar(environment_101829->data[i], 61, 0);
		result = copyStr(environment_101829->data[i], (NI64)(LOC5 + 1));
		goto BeforeRet;
	}	goto LA1;
	LA3: ;
	{
		NCSTRING env;
		env = getenv(key->data);
		{
			if (!(env == NIM_NIL)) goto LA9;
			result = copyString(((NimStringDesc*) &TMP58));
			goto BeforeRet;
		}		LA9: ;
		result = cstrToNimstr(env);
	}	LA1: ;
	BeforeRet: ;	return result;
}
N_NIMCALL(NI, searchextpos_100226)(NimStringDesc* s) {
	NI result;
	NI i_100238;
	NI HEX3Atmp_100250;
	NI res_100252;
	result = 0;
	result = -1;
	i_100238 = 0;
	HEX3Atmp_100250 = 0;
	HEX3Atmp_100250 = (NI64)(s->Sup.len - 1);
	res_100252 = HEX3Atmp_100250;
	while (1) {
		if (!(1 <= res_100252)) goto LA1;
		i_100238 = res_100252;
		{
			if (!((NU8)(s->data[i_100238]) == (NU8)(46))) goto LA4;
			result = i_100238;
			goto LA1;
		}		goto LA2;
		LA4: ;
		{
			if (!(((NU8)(s->data[i_100238])) == ((NU8)(47)) || ((NU8)(s->data[i_100238])) == ((NU8)(47)))) goto LA7;
			goto LA1;
		}		goto LA2;
		LA7: ;
		LA2: ;
		res_100252 -= 1;
	} LA1: ;
	return result;
}
N_NIMCALL(NimStringDesc*, normext_100220)(NimStringDesc* ext) {
	NimStringDesc* result;
	result = 0;
	{
		NIM_BOOL LOC3;
		LOC3 = 0;
		LOC3 = ((ext) && (ext)->Sup.len == 0);
		if (LOC3) goto LA4;
		LOC3 = ((NU8)(ext->data[0]) == (NU8)(46));
		LA4: ;
		if (!LOC3) goto LA5;
		result = copyString(ext);
	}	goto LA1;
	LA5: ;
	{
		NimStringDesc* LOC8;
		LOC8 = 0;
		LOC8 = rawNewString(ext->Sup.len + 1);
appendChar(LOC8, 46);
appendString(LOC8, ext);
		result = LOC8;
	}	LA1: ;
	return result;
}
N_NIMCALL(NimStringDesc*, nosChangeFileExt)(NimStringDesc* filename, NimStringDesc* ext) {
	NimStringDesc* result;
	NI extpos;
	result = 0;
	extpos = searchextpos_100226(filename);
	{
		NimStringDesc* LOC5;
		NimStringDesc* LOC6;
		if (!(extpos < 0)) goto LA3;
		LOC5 = 0;
		LOC6 = 0;
		LOC6 = normext_100220(ext);
		LOC5 = rawNewString(filename->Sup.len + LOC6->Sup.len + 0);
appendString(LOC5, filename);
appendString(LOC5, LOC6);
		result = LOC5;
	}	goto LA1;
	LA3: ;
	{
		NimStringDesc* LOC8;
		NimStringDesc* LOC9;
		NimStringDesc* LOC10;
		LOC8 = 0;
		LOC9 = 0;
		LOC9 = copyStrLast(filename, 0, (NI64)(extpos - 1));
		LOC10 = 0;
		LOC10 = normext_100220(ext);
		LOC8 = rawNewString(LOC9->Sup.len + LOC10->Sup.len + 0);
appendString(LOC8, LOC9);
appendString(LOC8, LOC10);
		result = LOC8;
	}	LA1: ;
	return result;
}
N_NIMCALL(NimStringDesc*, nosextractFilename)(NimStringDesc* path) {
	NimStringDesc* result;
	result = 0;
	{
		NIM_BOOL LOC3;
		LOC3 = 0;
		LOC3 = (path->Sup.len == 0);
		if (LOC3) goto LA4;
		LOC3 = (((NU8)(path->data[(NI64)(path->Sup.len - 1)])) == ((NU8)(47)) || ((NU8)(path->data[(NI64)(path->Sup.len - 1)])) == ((NU8)(47)));
		LA4: ;
		if (!LOC3) goto LA5;
		result = copyString(((NimStringDesc*) &TMP58));
	}	goto LA1;
	LA5: ;
	{
		TY86506 LOC8;
		memset((void*)&LOC8, 0, sizeof(LOC8));
		nosSplitPath(path, &LOC8);		result = copyString(LOC8.Field1);
	}	LA1: ;
	return result;
}
N_NIMCALL(time_t, nosgetLastModificationTime)(NimStringDesc* file) {
	time_t result;
	struct stat res;
	result = 0;
	memset((void*)&res, 0, sizeof(res));
	{
		int LOC3;
		NI32 LOC6;
		LOC3 = 0;
		LOC3 = stat(file->data, &res);
		if (!(LOC3 < ((NI32) 0))) goto LA4;
		LOC6 = 0;
		LOC6 = oslasterror_98046();
		oserror_98005(LOC6);	}	LA4: ;
	result = res.st_mtime;
	goto BeforeRet;
	BeforeRet: ;	return result;
}N_NOINLINE(void, pureosInit)(void) {
}

N_NOINLINE(void, pureosDatInit)(void) {
NTI101828.size = sizeof(TY101828*);
NTI101828.kind = 24;
NTI101828.base = (&NTI142);
NTI101828.flags = 2;
NTI101828.marker = TMP200;
}

