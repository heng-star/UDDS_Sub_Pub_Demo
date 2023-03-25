// Don't modify this file as it will be overwritten.
//
#include "IDL_UserDataType.h"

UserDataType::UserDataType(const UserDataType &IDL_s){
  x = IDL_s.x;
  y = IDL_s.y;
  color = IDL_s.color;
}

UserDataType& UserDataType::operator= (const UserDataType &IDL_s){
  if (this == &IDL_s) return *this;
  x = IDL_s.x;
  y = IDL_s.y;
  color = IDL_s.color;
  return *this;
}

void UserDataType::Marshal(CDR *cdr) const {
  cdr->PutShort(x);
  cdr->PutLong(y);
  cdr->PutString(color);
}

void UserDataType::UnMarshal(CDR *cdr){
  cdr->GetShort(x);
  cdr->GetLong(y);
  {
    char *IDL_str;
    cdr->GetString(IDL_str);
    if(color != NULL )
    {
        delete color;
        color = NULL;
    }
    color = IDL_str;
  }
}

