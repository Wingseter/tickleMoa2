

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 12:14:07 2038
 */
/* Compiler settings for database.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __database_i_h__
#define __database_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ImyDB_FWD_DEFINED__
#define __ImyDB_FWD_DEFINED__
typedef interface ImyDB ImyDB;

#endif 	/* __ImyDB_FWD_DEFINED__ */


#ifndef __myDB_FWD_DEFINED__
#define __myDB_FWD_DEFINED__

#ifdef __cplusplus
typedef class myDB myDB;
#else
typedef struct myDB myDB;
#endif /* __cplusplus */

#endif 	/* __myDB_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "shobjidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ImyDB_INTERFACE_DEFINED__
#define __ImyDB_INTERFACE_DEFINED__

/* interface ImyDB */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ImyDB;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9caf3c19-119b-4940-86ef-92e4248e4cdd")
    ImyDB : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE execQuery( 
            /* [in] */ BSTR query,
            /* [in] */ LONG option,
            /* [retval][out] */ VARIANT_BOOL *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE nextObj( 
            /* [retval][out] */ VARIANT_BOOL *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE getResultString( 
            /* [retval][out] */ BSTR *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE getResult( 
            /* [in] */ LONG nSubItem,
            /* [retval][out] */ BSTR *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE clearResult( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE connectDB( 
            /* [in] */ BSTR server,
            /* [in] */ BSTR db,
            /* [in] */ BSTR id,
            /* [in] */ BSTR pw,
            /* [retval][out] */ VARIANT_BOOL *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE exitDB( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ImyDBVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ImyDB * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ImyDB * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ImyDB * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ImyDB * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ImyDB * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ImyDB * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ImyDB * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *execQuery )( 
            ImyDB * This,
            /* [in] */ BSTR query,
            /* [in] */ LONG option,
            /* [retval][out] */ VARIANT_BOOL *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *nextObj )( 
            ImyDB * This,
            /* [retval][out] */ VARIANT_BOOL *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *getResultString )( 
            ImyDB * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *getResult )( 
            ImyDB * This,
            /* [in] */ LONG nSubItem,
            /* [retval][out] */ BSTR *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *clearResult )( 
            ImyDB * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *connectDB )( 
            ImyDB * This,
            /* [in] */ BSTR server,
            /* [in] */ BSTR db,
            /* [in] */ BSTR id,
            /* [in] */ BSTR pw,
            /* [retval][out] */ VARIANT_BOOL *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *exitDB )( 
            ImyDB * This);
        
        END_INTERFACE
    } ImyDBVtbl;

    interface ImyDB
    {
        CONST_VTBL struct ImyDBVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ImyDB_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ImyDB_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ImyDB_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ImyDB_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ImyDB_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ImyDB_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ImyDB_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ImyDB_execQuery(This,query,option,retval)	\
    ( (This)->lpVtbl -> execQuery(This,query,option,retval) ) 

#define ImyDB_nextObj(This,retval)	\
    ( (This)->lpVtbl -> nextObj(This,retval) ) 

#define ImyDB_getResultString(This,retval)	\
    ( (This)->lpVtbl -> getResultString(This,retval) ) 

#define ImyDB_getResult(This,nSubItem,retval)	\
    ( (This)->lpVtbl -> getResult(This,nSubItem,retval) ) 

#define ImyDB_clearResult(This)	\
    ( (This)->lpVtbl -> clearResult(This) ) 

#define ImyDB_connectDB(This,server,db,id,pw,retval)	\
    ( (This)->lpVtbl -> connectDB(This,server,db,id,pw,retval) ) 

#define ImyDB_exitDB(This)	\
    ( (This)->lpVtbl -> exitDB(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ImyDB_INTERFACE_DEFINED__ */



#ifndef __databaseLib_LIBRARY_DEFINED__
#define __databaseLib_LIBRARY_DEFINED__

/* library databaseLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_databaseLib;

EXTERN_C const CLSID CLSID_myDB;

#ifdef __cplusplus

class DECLSPEC_UUID("920d4a56-0399-42ca-b0a1-d47e43eba9af")
myDB;
#endif
#endif /* __databaseLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


