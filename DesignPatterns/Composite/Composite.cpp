#include<iostream>
#include<vector>
using namespace std;

class FileSystem{
    public:
    string name;
    virtual void ls() = 0;
};

class File : public FileSystem{
    public:

    File(string _file){
        name = _file;
    }

    void ls(){
        cout<<"File Name is - "<<name<<endl;
    }
};

class Directory : public FileSystem{
    public:
    
    vector<FileSystem*> filesystem;

    Directory(string _dir_name){
        name = _dir_name;
    }

    void add(FileSystem *fs){
        this->filesystem.push_back(fs);
    }

    void ls(){
        cout<<"Directory Name is - "<<name<<endl;

        for(FileSystem *fs : this->filesystem){
            fs->ls();
        }
    }
};

int main(){
    Directory *fs = new Directory("all_files");

    Directory *d1 = new Directory("photos");
    Directory *d2 = new Directory("videos");

    File *f1 = new File("photo1.png");
    FileSystem *f2 = new File("photo2.png");
    FileSystem *f4 = new File("info.txt");
    File *f3 = new File("video1.mp4");

    d1->add(f1);
    d1->add(f2);

    d2->add(f3);

    fs->add(d1);
    fs->add(f4);
    fs->add(d2);

    fs->ls();
    return 0;
}