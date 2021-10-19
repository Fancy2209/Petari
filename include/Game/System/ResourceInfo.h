#pragma once

#include <revolution.h>

class ResFileInfo {
public:
    ResFileInfo();

    void setName(const char *, bool);

    void* mResource; // _0
    u32 _4;
    u32 _8;
    u32 _C;
    char* mName;    // _10
    u32 mHashCode;  // _14
};

class ResTable {
public:
    ResTable();

    void newFileInfoTable(u32);
    ResFileInfo* add(const char *, void *, bool);
    const char* getResName(u32) const;
    void* getRes(u32) const;
    void* getRes(const char *) const;
    ResFileInfo* findFileInfo(const char *) const;
    ResFileInfo* getFileInfo(u32) const;
    bool isExistRes(const char *) const;
    int getResIndex(const char *) const;
    const char* findResName(const void *) const;
    const char* getResName(const void *) const;

    ResFileInfo* mFileInfoTable;    // _0
    u32 mCount;                     // _4

private:
    void* findRes(const char *) const;
};