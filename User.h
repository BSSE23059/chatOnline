#ifndef ONLINE_CHAT_USER_H
#define ONLINE_CHAT_USER_H
#include <unordered_map>
#include <vector>
#include <ctime>
#include <string>
using namespace std;

enum RequestStatus {
    UNREAD = 0,
    READ = 1,
    ACCEPTED = 2,
    REJECTED = 3
};

class Message {
public:
    int messageId;
    string message;
    time_t timeStamp;
    Message(int id, string msg, time_t time);
};

class AddRequest {
public:
    int fromUserId;
    int toUserId;
    RequestStatus requestStatus;
    time_t timeStamp;
    AddRequest(int fromId, int toId, RequestStatus status, time_t time);
};

class Chat {
public:
    int chatId;
    static vector <int> users;
    vector <Message> messages;
    explicit Chat(int id);
};

class PrivateChat : public Chat {
public:
    PrivateChat(int firstUser, int secondUser);
};

class GroupChat : public Chat {
public:
    static void addUser(int user);
    static void removeUser(int user);
    static void displayUsers();
};

class User {
public:
    int userId;
    string name;
    string passHash;
    unordered_map<int, User*> friendsById;
    unordered_map<int, PrivateChat*> friendIdsToPrivateChats;
    unordered_map<int, GroupChat*> groupChatsById;
    unordered_map<int, AddRequest*> receivedFriendRequestsByFriendId;
    unordered_map<int, AddRequest*> sentFriendRequestsByFriendId;

    User(int id,string n,string  pass);
    void messageUser(int friendId, const string& message);
    void messageGroup(int groupId, const string& message);
    void sendFriendRequest(int friendId);
    void receiveFriendRequest(int friendId);
    void approveFriendRequest(int friend_id);
    void rejectFriendRequest(int friend_id);
};

class UserService {
public:
    unordered_map<int, User*> usersById;

    void addUser(int userId, const string& name, const string& passHash);
    void removeUser(int userId);
    void addFriendRequest(int fromUserId, int toUserId);
    void approveFriendRequest(int fromUserId, int toUserId);
    void rejectFriendRequest(int fromUserId, int toUserId);
};

#endif //ONLINE_CHAT_USER_H
