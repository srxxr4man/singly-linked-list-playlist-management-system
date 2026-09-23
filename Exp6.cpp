#include <iostream>
#include <string>
using namespace std;

struct Song{
    int id;
    string name;
    string artist;
    Song *next;
};

void getSongDetails(int &id,string &name,string &artist){
    cout<<"Enter the Song ID: ";
    cin>>id;
    cout<<"Enter the Song Name: ";
    cin>>name;
    cout<<"Enter the Name of Artist: ";
    cin>>artist;
}

void addFront(int id,string name,string artist,Song *&head){
    Song *newSong=new Song();
    newSong->id=id;
    newSong->name=name;
    newSong->artist=artist;
    newSong->next=head;
    head=newSong;
    cout<<"Song added to the front of the playlist"<<endl;
}

void addBack(int id,string name,string artist,Song *&head){
    Song *newSong=new Song();
    newSong->id=id;
    newSong->name=name;
    newSong->artist=artist;
    newSong->next=NULL;
    
    if (head==NULL){
        head=newSong;
        cout<<"Song added to the playlist"<<endl;
        return;
    }
    
    Song *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newSong;
    cout<<"Song added to the end of the playlist"<<endl;
}

void addSpecific(int id,string name,string artist,int afterId,Song *&head){
    Song *temp=head;
    while(temp && temp->id!=afterId){
        temp=temp->next;
    }
    
    if (temp==NULL){
        cout<<"Song ID NOT Found"<<endl;
        return;
    }
    
    Song *newSong=new Song();
    newSong->id=id;
    newSong->name=name;
    newSong->artist=artist;
    newSong->next=temp->next;
    temp->next=newSong;
    cout<<"Song added after ID "<<afterId<<" of the playlist"<<endl;
}

void display(Song *&head){
    if (head==NULL){
        cout<<"Playlist is Empty"<<endl;
        return;
    }
    
    Song *temp=head;
    while(temp!=NULL){
        cout<<"| ID: "<<temp->id<<" | Name: "<<temp->name<<" | Artist: "<<temp->artist<<" | "<<" -> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

void deleteFront(Song *&head){
    if (head==NULL){
        cout<<"Playlist is Empty"<<endl;
        return;
    }
    
    Song *temp=head;
    head=head->next;
    delete temp;
    cout<<"Song deleted from the front of the playlist"<<endl;
}

void deleteBack(Song *&head){
    if (head==NULL){
        cout<<"Playlist is Empty"<<endl;
        return;
    }
    
    if (head->next==NULL){
        delete head;
        head=NULL;
        cout<<"Song Delete Successfully"<<endl;
        return;
    }
    
    Song *temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    
    delete temp->next;
    temp->next=NULL;
    cout<<"Song deleted fromt the end of the playlist"<<endl;
}

void deleteSpecific(Song *&head,int deleteId){
    if (head==NULL){
        cout<<"Playlist is Empty"<<endl;
        return;
    }
    
    if(head->id==deleteId){
        Song *temp=head;
        head=head->next;
        delete temp;
        cout<<"Song with ID "<<deleteId<<" deleted from the playlist"<<endl;
        return;
    }
    
    Song *temp=head;
    while(temp->next && temp->next->id!=deleteId){
        temp=temp->next;
    }
    
    if(temp->next==NULL){
        cout<<"Song ID NOT Found"<<endl;
        return;
    }
    
    Song *toDelete=temp->next;
    temp->next=toDelete->next;
    delete toDelete;
    cout<<"Song with ID "<<deleteId<<" deleted from the playlist"<<endl;
}

int main(){
    Song *head=NULL;
    int id,afterId,deleteId,choice;
    string name,artist;
    
    do{
        cout<<"\nPlaylist Management System"<<endl;
        cout<<"----------------------------"<<endl;
        cout<<"1. Add a Song at Front"<<endl;
        cout<<"2. Add a Song at Back"<<endl;
        cout<<"3. Add a Song after specified Song ID"<<endl;
        cout<<"4. Display Playlist"<<endl;
        cout<<"5. Delete a Song from Front"<<endl;
        cout<<"6. Delete a Song from Back"<<endl;
        cout<<"7. Delete a Song with Song ID"<<endl;
        cout<<"8. Exit"<<endl;
        
        cout<<"Enter the Choice: ";
        cin>>choice;
        
        switch(choice){
            case 1:
                getSongDetails(id,name,artist);
                addFront(id,name,artist,head);
                break;
                
            case 2:
                getSongDetails(id,name,artist);
                addBack(id,name,artist,head);
                break;
                
            case 3:
                getSongDetails(id,name,artist);
                cout<<"Enter the Song ID after which you want to add Song: ";
                cin>>afterId;
                addSpecific(id,name,artist,afterId,head);
                break;
                
            case 4:
                display(head);
                break;
                
            case 5:
                deleteFront(head);
                break;
            
            case 6:
                deleteBack(head);
                break;
                
            case 7:
                cout<<"Enter the Song ID you want to Delete: ";
                cin>>deleteId;
                deleteSpecific(head,deleteId);
                break;
                
            case 8:
                cout<<"Exiting..."<<endl;
                break;
                
            default:
                cout<<"Invalid Choice"<<endl;
                break;
        }
    } while (choice!=8);
    
    return 0;
}