#include "wrapper.h"

extern "C"
{

EWXWEXPORT(void*, wxValidator_Create)()
{
	return (void*) new wxValidator();
}

EWXWEXPORT(void, wxValidator_Delete)(void* _obj)
{
	delete (wxValidator*)_obj;
}

EWXWEXPORT(int, wxValidator_Validate)(void* _obj, void* parent)
{
	return (int)((wxValidator*)_obj)->Validate((wxWindow*)parent);
}
	
EWXWEXPORT(int, wxValidator_TransferToWindow)(void* _obj)
{
	return (int)((wxValidator*)_obj)->TransferToWindow();
}
	
EWXWEXPORT(int, wxValidator_TransferFromWindow)(void* _obj)
{
	return (int)((wxValidator*)_obj)->TransferFromWindow();
}
	
EWXWEXPORT(void*, wxValidator_GetWindow)(void* _obj)
{
	return (void*)((wxValidator*)_obj)->GetWindow();
}
	
EWXWEXPORT(void, wxValidator_SetWindow)(void* _obj, void* win)
{
	((wxValidator*)_obj)->SetWindow((wxWindowBase*)win);
}
	
#if (wxVERSION_NUMBER < 2800)	
EWXWEXPORT(int, wxValidator_IsSilent)()
{
	return (int)wxValidator::IsSilent();
}
#endif
	
EWXWEXPORT(void, wxValidator_SetBellOnError)(int doIt)
{
	wxValidator::SetBellOnError(doIt != 0);
}
	
EWXWEXPORT(void*, wxTextValidator_Create)(int style, void* val)
{
	return (void*) new wxTextValidator((long)style, new wxString);
}

EWXWEXPORT(int, wxTextValidator_GetStyle)(void* _obj)
{
	return (int)((wxTextValidator*)_obj)->GetStyle();
}
	
EWXWEXPORT(void, wxTextValidator_SetStyle)(void* _obj, int style)
{
	((wxTextValidator*)_obj)->SetStyle((long) style);
}
	
#if (wxVERSION_NUMBER < 2800)	
EWXWEXPORT(void, wxTextValidator_SetIncludeList)(void* _obj, void* list, int count)
{
#if (wxVERSION_NUMBER <= 2600)
	wxStringList str;
	
	for (int i = 0; i < count; i++)
		str.Add(((wxChar**)list)[i]);
		
	((wxTextValidator*)_obj)->SetIncludeList(str);
#else
	((wxTextValidator*)_obj)->SetIncludes((const wxArrayString&)list);
#endif
}
	
EWXWEXPORT(int, wxTextValidator_GetIncludeList)(void* _obj, void* _ref)
{
#if (wxVERSION_NUMBER <= 2600)
	if (_ref)
	{
		for (unsigned int i = 0; i < ((wxTextValidator*)_obj)->GetIncludeList().GetCount(); i++)
			((const wxChar**)_ref)[i] = wxStrdup(((wxTextValidator*)_obj)->GetIncludeList().Item(i)->GetData());
	}
	return ((wxTextValidator*)_obj)->GetIncludeList().GetCount();
#else
	wxArrayString arr = ((wxTextValidator*)_obj)->GetIncludes();
	if (_ref)
	{
		for (unsigned int i = 0; i < arr.GetCount(); i++)
			((const wxChar**)_ref)[i] = wxStrdup (arr.Item(i).c_str());
	}
	return arr.GetCount();
#endif
}
	
EWXWEXPORT(void, wxTextValidator_SetExcludeList)(void* _obj, void* list, int count)
{
#if (wxVERSION_NUMBER <= 2600)
	wxStringList str;
	
	for (int i = 0; i < count; i++)
		str.Add(((wxChar**)list)[i]);
		
	((wxTextValidator*)_obj)->SetExcludeList(str);
#else
	((wxTextValidator*)_obj)->SetExcludes((const wxArrayString&)list);
#endif
}
	
EWXWEXPORT(int, wxTextValidator_GetExcludeList)(void* _obj, void* _ref)
{
#if (wxVERSION_NUMBER <= 2600)
	if (_ref)
	{
		for (unsigned int i = 0; i < ((wxTextValidator*)_obj)->GetExcludeList().GetCount(); i++)
			((const wxChar**)_ref)[i] = ((wxTextValidator*)_obj)->GetExcludeList().Item(i)->GetData();
	}
	return ((wxTextValidator*)_obj)->GetExcludeList().GetCount();
#else
	wxArrayString arr = ((wxTextValidator*)_obj)->GetExcludes();
	if (_ref)
	{
		for (unsigned int i = 0; i < arr.GetCount(); i++)
			((const wxChar**)_ref)[i] = wxStrdup (arr.Item(i).c_str());
	}
	return arr.GetCount();
#endif
}
#else
EWXWEXPORT(void, wxTextValidator_SetIncludes)(void* _obj, void* list, int count)
{
  wxArrayString str;
  
  for (int i = 0; i < count; i++)
    str.Add(((wxChar**)list)[i]);
  
  ((wxTextValidator*)_obj)->SetIncludes(str);
}

EWXWEXPORT(void *, wxTextValidator_GetIncludes)(void* _obj, int *_nitems)
{
  void *retval = NULL;

  if (_nitems != NULL)
  {
    wxArrayString items = ((wxTextValidator*)_obj)->GetIncludes();
    wxChar **items_copy = (wxChar **) malloc(sizeof(wxChar *) * items.GetCount());

    for (unsigned int i = 0; i < items.GetCount(); i++)
    {
      items_copy[i] = wxStrdup(items.Item(i).GetData());
    }
    retval = (void *) items_copy;
    *_nitems = items.GetCount();
  }
  return retval;
}
	
EWXWEXPORT(void, wxTextValidator_SetExcludes)(void* _obj, void* list, int count)
{
	wxArrayString str;
	
	for (int i = 0; i < count; i++)
		str.Add(((wxChar**)list)[i]);
		
	((wxTextValidator*)_obj)->SetExcludes(str);
}
	
EWXWEXPORT(void *, wxTextValidator_GetExcludes)(void* _obj, int* _nitems)
{
  void *retval = NULL;

  if (_nitems != NULL)
  {
    wxArrayString items = ((wxTextValidator*)_obj)->GetExcludes();
    wxChar **items_copy = (wxChar **) malloc(sizeof(wxChar *) * items.GetCount());

    for (unsigned int i = 0; i < items.GetCount(); i++)
    {
      items_copy[i] = wxStrdup(items.Item(i).GetData());
    }
    retval = (void *) items_copy;
    *_nitems = items.GetCount();
  }
  return retval;
}

EWXWEXPORT(void *, wxTextValidator_Clone)(void *_obj)
{
  return (void *)((wxTextValidator*)_obj)->Clone();
}

EWXWEXPORT(int, wxTextValidator_TransferToWindow)(void* _obj)
{
	return (int)((wxTextValidator*)_obj)->TransferToWindow();
}
	
EWXWEXPORT(int, wxTextValidator_TransferFromWindow)(void* _obj)
{
	return (int)((wxTextValidator*)_obj)->TransferFromWindow();
}
	
#endif

EWXWEXPORT(void, wxTextValidator_OnChar)(void* _obj, void* event)
{
	((wxTextValidator*)_obj)->OnChar(*((wxKeyEvent*)event));
}

EWXWEXPORT(void*, ELJTextValidator_Create) (void* _obj, void* _fnc, void* _txt, long _stl)
{
	return new ELJTextValidator(_obj, _fnc, _txt, _stl);
}

}

bool ELJTextValidator::Validate(wxWindow* _prt)
{
	if (obj && fnc)
		return fnc(obj) != 0;
	else
		return wxTextValidator::Validate(_prt);
}
