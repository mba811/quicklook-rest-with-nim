/* Generated by Nimrod Compiler v0.9.5 */
/*   (c) 2014 Andreas Rumpf */
/* The generated code is subject to the original license. */
#define NIM_INTBITS 64
#include "nimbase.h"

#include <string.h>
typedef struct TNimType TNimType;
typedef struct TNimNode TNimNode;
typedef struct tbaselexer127014 tbaselexer127014;
typedef struct TNimObject TNimObject;
typedef struct tstream124835 tstream124835;
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
struct  TNimObject  {
TNimType* m_type;
};
struct  tbaselexer127014  {
  TNimObject Sup;
NI Bufpos;
NCSTRING Buf;
NI Buflen;
tstream124835* Input;
NI Linenumber;
NI Sentinel;
NI Linestart;
NIM_BOOL Fileopened;
};
typedef N_NIMCALL_PTR(void, TY124836) (tstream124835* s);
typedef N_NIMCALL_PTR(NIM_BOOL, TY124840) (tstream124835* s);
typedef N_NIMCALL_PTR(void, TY124844) (tstream124835* s, NI pos);
typedef N_NIMCALL_PTR(NI, TY124849) (tstream124835* s);
typedef N_NIMCALL_PTR(NI, TY124853) (tstream124835* s, void* buffer, NI buflen);
typedef N_NIMCALL_PTR(void, TY124859) (tstream124835* s, void* buffer, NI buflen);
typedef N_NIMCALL_PTR(void, TY124865) (tstream124835* s);
struct  tstream124835  {
  TNimObject Sup;
TY124836 Closeimpl;
TY124840 Atendimpl;
TY124844 Setpositionimpl;
TY124849 Getpositionimpl;
TY124853 Readdataimpl;
TY124859 Writedataimpl;
TY124865 Flushimpl;
};
N_NIMCALL(void, unsureAsgnRef)(void** dest, void* src);
N_NOCONV(void*, alloc_5401)(NI size);
N_NIMCALL(void, fillbuffer_127091)(tbaselexer127014* l);
N_NIMCALL(NI, readdata_124977)(tstream124835* s, void* buffer, NI buflen);
N_NOCONV(void*, realloc_5433)(void* p, NI newsize);
N_NIMCALL(void, skiputf8bom_128419)(tbaselexer127014* l);
N_NIMCALL(NI, fillbaselexer_127820)(tbaselexer127014* l, NI pos);
N_NOCONV(void, dealloc_5448)(void* p);
N_NIMCALL(void, close_124888)(tstream124835* s);
extern TNimType NTI2811; /* TObject */
TNimType NTI127014; /* TBaseLexer */
extern TNimType NTI112; /* int */
extern TNimType NTI159; /* cstring */
extern TNimType NTI124833; /* PStream */
extern TNimType NTI146; /* bool */

N_NIMCALL(void, fillbuffer_127091)(tbaselexer127014* l) {
	NI charsread;
	NI tocopy;
	NI s;
	NI oldbuflen;
	NI LOC5;
	charsread = 0;
	tocopy = 0;
	s = 0;
	oldbuflen = 0;
	tocopy = (NI64)((NI64)((*l).Buflen - (*l).Sentinel) - 1);
	{
		if (!(0 < tocopy)) goto LA3;
		memmove(((void*) ((*l).Buf)), ((void*) (&(*l).Buf[(NI64)((*l).Sentinel + 1)])), (NI64)(tocopy * 1));
	}
	LA3: ;
	LOC5 = 0;
	LOC5 = readdata_124977((*l).Input, ((void*) (&(*l).Buf[tocopy])), (NI64)((NI64)((*l).Sentinel + 1) * 1));
	charsread = (NI64)(LOC5 / 1);
	s = (NI64)(tocopy + charsread);
	{
		if (!(charsread < (NI64)((*l).Sentinel + 1))) goto LA8;
		(*l).Buf[s] = 0;
		(*l).Sentinel = s;
	}
	goto LA6;
	LA8: ;
	{
		s -= 1;
		while (1) {
			while (1) {
				NIM_BOOL LOC13;
				LOC13 = 0;
				LOC13 = (0 <= s);
				if (!(LOC13)) goto LA14;
				LOC13 = !((((NU8)((*l).Buf[s])) == ((NU8)(13)) || ((NU8)((*l).Buf[s])) == ((NU8)(10))));
				LA14: ;
				if (!LOC13) goto LA12;
				s -= 1;
			} LA12: ;
			{
				if (!(0 <= s)) goto LA17;
				(*l).Sentinel = s;
				goto LA11;
			}
			goto LA15;
			LA17: ;
			{
				void* LOC20;
				NI LOC21;
				oldbuflen = (*l).Buflen;
				(*l).Buflen = (NI64)((*l).Buflen * 2);
				LOC20 = 0;
				LOC20 = realloc_5433(((void*) ((*l).Buf)), (NI64)((*l).Buflen * 1));
				(*l).Buf = ((NCSTRING) (LOC20));
				LOC21 = 0;
				LOC21 = readdata_124977((*l).Input, ((void*) (&(*l).Buf[oldbuflen])), (NI64)(oldbuflen * 1));
				charsread = (NI64)(LOC21 / 1);
				{
					if (!(charsread < oldbuflen)) goto LA24;
					(*l).Buf[(NI64)(oldbuflen + charsread)] = 0;
					(*l).Sentinel = (NI64)(oldbuflen + charsread);
					goto LA11;
				}
				LA24: ;
				s = (NI64)((*l).Buflen - 1);
			}
			LA15: ;
		} LA11: ;
	}
	LA6: ;
}

N_NIMCALL(void, skiputf8bom_128419)(tbaselexer127014* l) {
	{
		NIM_BOOL LOC3;
		NIM_BOOL LOC4;
		LOC3 = 0;
		LOC4 = 0;
		LOC4 = ((NU8)((*l).Buf[0]) == (NU8)(239));
		if (!(LOC4)) goto LA5;
		LOC4 = ((NU8)((*l).Buf[1]) == (NU8)(187));
		LA5: ;
		LOC3 = LOC4;
		if (!(LOC3)) goto LA6;
		LOC3 = ((NU8)((*l).Buf[2]) == (NU8)(191));
		LA6: ;
		if (!LOC3) goto LA7;
		(*l).Bufpos += 3;
		(*l).Linestart += 3;
	}
	LA7: ;
}

N_NIMCALL(void, open_127026)(tbaselexer127014* l, tstream124835* input, NI buflen) {
	void* LOC1;
	unsureAsgnRef((void**) &(*l).Input, input);
	(*l).Bufpos = 0;
	(*l).Buflen = buflen;
	LOC1 = 0;
	LOC1 = alloc_5401((NI64)(buflen * 1));
	(*l).Buf = ((NCSTRING) (LOC1));
	(*l).Sentinel = (NI64)(buflen - 1);
	(*l).Linestart = 0;
	(*l).Linenumber = 1;
	fillbuffer_127091(l);
	skiputf8bom_128419(l);
}

N_NIMCALL(NI, fillbaselexer_127820)(tbaselexer127014* l, NI pos) {
	NI result;
	result = 0;
	{
		if (!(pos < (*l).Sentinel)) goto LA3;
		result = (NI64)(pos + 1);
	}
	goto LA1;
	LA3: ;
	{
		fillbuffer_127091(l);
		(*l).Bufpos = 0;
		result = 0;
	}
	LA1: ;
	(*l).Linestart = result;
	return result;
}

N_NIMCALL(NI, handlecr_127057)(tbaselexer127014* l, NI pos) {
	NI result;
	result = 0;
	(*l).Linenumber += 1;
	result = fillbaselexer_127820(l, pos);
	{
		if (!((NU8)((*l).Buf[result]) == (NU8)(10))) goto LA3;
		result = fillbaselexer_127820(l, result);
	}
	LA3: ;
	return result;
}

N_NIMCALL(NI, handlelf_127065)(tbaselexer127014* l, NI pos) {
	NI result;
	result = 0;
	(*l).Linenumber += 1;
	result = fillbaselexer_127820(l, pos);
	return result;
}

N_NIMCALL(NI, getcolnumber_127050)(tbaselexer127014* l, NI pos) {
	NI result;
	result = 0;
	result = ((NI64)(pos - (*l).Linestart) > 0? ((NI64)(pos - (*l).Linestart)) : -((NI64)(pos - (*l).Linestart)));
	return result;
}

N_NIMCALL(void, close_127036)(tbaselexer127014* l) {
	dealloc_5448(((void*) ((*l).Buf)));
	close_124888((*l).Input);
}
N_NOINLINE(void, stdlib_lexbaseInit)(void) {
}

N_NOINLINE(void, stdlib_lexbaseDatInit)(void) {
static TNimNode* TMP148[8];
static TNimNode TMP27[9];
NTI127014.size = sizeof(tbaselexer127014);
NTI127014.kind = 17;
NTI127014.base = (&NTI2811);
TMP148[0] = &TMP27[1];
TMP27[1].kind = 1;
TMP27[1].offset = offsetof(tbaselexer127014, Bufpos);
TMP27[1].typ = (&NTI112);
TMP27[1].name = "bufpos";
TMP148[1] = &TMP27[2];
TMP27[2].kind = 1;
TMP27[2].offset = offsetof(tbaselexer127014, Buf);
TMP27[2].typ = (&NTI159);
TMP27[2].name = "buf";
TMP148[2] = &TMP27[3];
TMP27[3].kind = 1;
TMP27[3].offset = offsetof(tbaselexer127014, Buflen);
TMP27[3].typ = (&NTI112);
TMP27[3].name = "bufLen";
TMP148[3] = &TMP27[4];
TMP27[4].kind = 1;
TMP27[4].offset = offsetof(tbaselexer127014, Input);
TMP27[4].typ = (&NTI124833);
TMP27[4].name = "input";
TMP148[4] = &TMP27[5];
TMP27[5].kind = 1;
TMP27[5].offset = offsetof(tbaselexer127014, Linenumber);
TMP27[5].typ = (&NTI112);
TMP27[5].name = "lineNumber";
TMP148[5] = &TMP27[6];
TMP27[6].kind = 1;
TMP27[6].offset = offsetof(tbaselexer127014, Sentinel);
TMP27[6].typ = (&NTI112);
TMP27[6].name = "sentinel";
TMP148[6] = &TMP27[7];
TMP27[7].kind = 1;
TMP27[7].offset = offsetof(tbaselexer127014, Linestart);
TMP27[7].typ = (&NTI112);
TMP27[7].name = "lineStart";
TMP148[7] = &TMP27[8];
TMP27[8].kind = 1;
TMP27[8].offset = offsetof(tbaselexer127014, Fileopened);
TMP27[8].typ = (&NTI146);
TMP27[8].name = "fileOpened";
TMP27[0].len = 8; TMP27[0].kind = 2; TMP27[0].sons = &TMP148[0];
NTI127014.node = &TMP27[0];
}
