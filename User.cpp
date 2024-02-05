#include <iostream>
#include <utility>
#include "User.h"
#include <unordered_map>
using namespace std;

Message::Message(int id, std::string msg, time_t time) :
messageId(id), message(std::move(msg)), timeStamp(time) {}

AddRequest::AddRequest(int fromId, int toId, RequestStatus status, time_t time) :
fromUserId(fromId), toUserId(toId), requestStatus(status), timeStamp(time) {}

Chat::Chat(int id) : chatId(id) {}

PrivateChat::PrivateChat(int firstUser, int secondUser) : Chat(0) {
    users.push_back(firstUser);
    users.push_back(secondUser);
}

void GroupChat::addUser(int user) {
}

void GroupChat::removeUser(int user) {
}

void GroupChat::displayUsers() {

}

User::User(int id,std::string  n,std::string  pass)
: userId(id), name(std::move(n)), passHash(std::move(pass)) {}

void User::messageUser(int friendId, const std::string &message) {
}

void User::messageGroup(int groupId, const std::string &message) {}

void User::sendFriendRequest(int friendId) {
    UserService userService;
    auto friendUserIterator = userService.usersById.find(friendId);
    if(userService.usersById.find(friendId) != userService.usersById.end()){
        auto *addRequest = new AddRequest(userId,friendId,UNREAD,time(nullptr));
        sentFriendRequestsByFriendId[friendId] = addRequest;
        friendUserIterator->second->receivedFriendRequestsByFriendId[friendId] = addRequest;
        cout << "Friend request sent to " << friendId << endl;
    } else {
        cout << "User with " << friendId << " does not exist." << endl;
    }
}

void User::receiveFriendRequest(int friendId) {

}

void User::approveFriendRequest(int friend_id) {}

void User::rejectFriendRequest(int friend_id) {}


void UserService::addUser(int userId, const std::string &name, const std::string &passHash) {
    if(usersById.find(userId) != usersById.end()){
        cout << name << " is already registered." << endl;
    } else {
        UserService userService;
        User* user = new User(userId,name,passHash);
        userService.usersById.emplace(userId,user);
        cout << name << " is registered successfully." << endl;
    }
}

void UserService::removeUser(int userId) {

}

void UserService::addFriendRequest(int fromUserId, int toUserId) {


}


void UserService::approveFriendRequest(int fromUserId, int toUserId) {}

void UserService::rejectFriendRequest(int fromUserId, int toUserId) {}