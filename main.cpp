#include <iostream>
#include <vector>

using namespace std;

class Note{
protected:
    string title;
public:
    string getTitle(){return title;}
    void setTitle(string value){title=value;}
    virtual string getContent();
    virtual void setContent(string);
};

class TextNote : public Note{
    string content;
public:
    string getContent() override{
        return content;
    }
    void setContent(string value) override{
        content = value;
    }
};

class ListNote : public Note{
    string content;
public:
    string getContent() override{
        return content;
    }
    void setContent(string value) override{
        content = value;
    }
};

class NoteDirector{
    vector<Note> notes;
public:
    void addNote(const Note& note){
        notes.push_back(note);
    }
    void deleteNote(int index){
        notes.erase(notes.begin()+ index);
    }
    Note getNote(int index){
        return notes[index];
    }
    void editNote(int index, const Note& note){
        notes[index] = note;
    }
    void clearNotesList(){
        notes.clear();
    }
};

int main() {
    NoteDirector director;
    TextNote t1;
    t1.setTitle("t1");
    t1.setContent("content 1");
    ListNote t2;
    t2.setTitle("t2");
    t2.setContent("content 2");
    director.addNote(t1);
    director.addNote(t2);
    director.clearNotesList();
    return 0;
}
