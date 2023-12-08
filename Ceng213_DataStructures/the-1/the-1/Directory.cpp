#include "Directory.h"

File Directory::getFile(int index) const
{
	/* TODO */
	if(index < 0 || index >= files.size()) return File();
    else{
        return files[index];
    }
}

size_t Directory::directorySize() const
{
	/* TODO */
	size_t totalSize = 0;

    for (int i = 0; i < files.size(); ++i) {
        totalSize += files[i].fileSize();
    }

    return totalSize;
}

bool Directory::isEmpty() const
{
	/* TODO */
	return files.empty();
}

size_t Directory::numFiles() const
{
	/* TODO */
	return files.size();
}

void Directory::newFile(const File &file)
{
	/* TODO */
	files.push_back(file);
}

void Directory::removeFile(int index)
{
	/* TODO */
	if (index >= 0 && index < files.size()) {
        files.erase(files.begin() + index);
    }
}

void Directory::removeFile(File &file)
{
	/* TODO */
	int index=0;
    for (int i = 0; i < files.size(); i++) {
        if (files[i] == file){
            index = i;
            break;
        } 
    }
    removeFile(index);
}

void Directory::removeBiggestFile()
{
	/* TODO */
	if (files.empty()) {
        return;
    }

    size_t maxSize = 0;
    int index = -1;

    for (int i = 0; i < files.size(); i++) {
        size_t fileSize = files[i].fileSize();
        if (fileSize == maxSize) continue;
        if (fileSize > maxSize) {
            maxSize = fileSize;
            index = i;
        }
    }
    removeFile(index);
}
