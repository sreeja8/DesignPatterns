#include <iostream>
#include <list>

using namespace std;

class ISubscriber{
    public:
        virtual void notify(string msg) = 0;
};

class User : public ISubscriber{
    private:
        int userID;
    public:
        User(int id){
            this->userID = id;
        }
        void notify(string msg){
            cout<<"User "<<userID<<" received msg "<<msg<<endl;
        }
};

class Group{
    private:
        list <ISubscriber*> subscribers;
    public:
        void subscribe(ISubscriber* user){
            subscribers.push_back(user);
        }
        void unsubscribe(ISubscriber* user){
            subscribers.remove(user);
        }
        void notifyGroup(string msg){
            for(auto user : subscribers){
                user->notify(msg);
            }
        }
};

int main()
{
    Group* group = new Group;

    User* user1 = new User(1);
    User* user2 = new User(2);
    User* user3 = new User(3);

    group->subscribe(user1);
    group->subscribe(user2);
    group->subscribe(user3);

    group->notifyGroup("New msg");

    group->unsubscribe(user1);

    group->notifyGroup("New new msg");

    return 0;
}