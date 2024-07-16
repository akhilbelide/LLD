#include<iostream>
#include<vector>
using namespace std;


enum Type{
    F,
    D
};

// Composite Pattern
class FileNode{
    private:
    string name;
    int size;
    Type type;

    public:
    FileNode(string _name, int _size, Type _type){
        name = _name;
        size = _size;
        type = _type;
    }

    string getName(){
        return this->name;
    }

    int getSize(){
        return this->size;
    }

    void setName(string _name){
        this->name = _name;
    }

    void setSize(int _size){
        this->size = _size;
    }

    void setType(Type _type){
        this->type = _type;
    }

    Type getType(){
        return this->type;
    }

    virtual ~FileNode() = default;
};

class File : public FileNode{
    private:
    string extension;

    public:
    File(string name, int size, string _ext) : FileNode(name, size, F){
        extension = _ext;
    }
    string getExtension(){
        return this->extension;
    }

    void setExtendion(string _ext){
        extension = _ext;
    }
};

class Directory : public FileNode{
    private:
    vector<FileNode*> children;

    public:
    Directory(string name) : FileNode(name, 0, D){
        
    }

    Directory(string name, vector<FileNode*> _children): FileNode(name, 0, D){
        children = _children;
    }

    void add(FileNode* node){
        children.push_back(node);
    }

    vector<FileNode*> getChild(){
        return this->children;
    }
};

class Filter{
    public:
    virtual bool apply(FileNode* file)=0;
};

class FileNameFilter : public Filter{
    public:
    string name;
    FileNameFilter(string _name){
        name = _name;
    }
    bool apply(FileNode* file){
        return file->getName() == this->name;
    }
};

class GreaterThanSizeFilter : public Filter{
    public:
    int size;
    GreaterThanSizeFilter(int _size){
        size = _size;
    }
    bool apply(FileNode* file){
        return file->getSize() > size;
    }
};

class DefFilter : public Filter{
    public:
    int size;
    DefFilter(){
        
    }
    bool apply(FileNode* file){
        return true;
    }
};

class ANDFilter : public Filter{
    public:
    Filter *f1;
    Filter *f2;
    ANDFilter(Filter *_f1, Filter *_f2){
        f1 = _f1;
        f2 = _f2;
    }

    bool apply(FileNode* file){
        return f1->apply(file) && f2->apply(file);
    }
};

class ORFilter : public Filter{
    public:
    Filter *f1;
    Filter *f2;
    ORFilter(Filter *_f1, Filter *_f2){
        f1 = _f1;
        f2 = _f2;
    }

    bool apply(FileNode* file){
        return f1->apply(file) || f2->apply(file);
    }
};

class Builder{
    public:
    Filter *f;
    Builder(){
        f = new  DefFilter();
    }

    Builder* orOp(Filter *_new_filter){
        f = new ORFilter(this->f, _new_filter);
        return this;
    }

    Builder* andOp(Filter *_new_filter){
        f = new ANDFilter(this->f, _new_filter);
        return this;
    }

    Filter* build(){
        return this->f;
    }

};

void findHelper(FileNode* root, Filter *f, vector<FileNode*> &ans){
    if(root->getType()==F){
        if(f->apply(root)){
            ans.push_back(root);
        }
    }
    else if(root->getType()==D){
        Directory *dir = dynamic_cast<Directory*>(root);
        vector<FileNode*> childs = dir->getChild();
        for(FileNode* node : childs){
            findHelper(node, f, ans);
        }
    }
}

vector<FileNode*> findAPI(FileNode* root, Filter *f){
    vector<FileNode*> ans;
    findHelper(root, f, ans);
    return ans;
}

int main(){
    Directory* root = new Directory("/");
    FileNode* file1 = new File("file1", 20, "pdf");
    FileNode* file2 = new File("file2", 40, "pdf");
    FileNode* file3 = new File("file3", 75, "pdf");
    FileNode* file4 = new File("file4", 10, "pdf");

    root->add(file1);
   
    vector<FileNode*> childs;
    childs.push_back(file2);
    childs.push_back(file3);
    
    Directory *dir2 = new Directory("second");
    dir2->add(file4);
    childs.push_back(dir2);
    Directory *dir1 = new Directory("first", childs);
    root->add(dir1);

    //Filter *f = new GreaterThanSizeFilter(10);
    //only one criteria, but how if you want to have mor ethan one? - builder pattern?

    Builder *filter_builder = new Builder();
    Filter *f = filter_builder->andOp(new GreaterThanSizeFilter(10))
    ->build();
    //->andOp(new FileNameFilter("file2"))->build();
    vector<FileNode*> target = findAPI(root, f);

    if(target.size()>0){
        for(FileNode* file : target){
            cout<<file->getName()<<" - "<<file->getSize()<<endl;;
        }
    }
    else cout<<"NO FILES"<<endl;
}