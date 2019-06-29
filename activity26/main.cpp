#include <iostream>

struct UserProfile {};
struct UserId {};

class UserProfileStorage {
    public:
        virtual UserProfile getUserProfile(const UserId& id) const = 0;
        virtual ~UserProfileStorage() = default;
    protected:
        UserProfileStorage() = default;
        UserProfileStorage(const UserProfileStorage&) = default;
        UserProfileStorage& operator=(const UserProfileStorage&) = default;
};

class UserProfileCache : public UserProfileStorage {
    public:
        UserProfile getUserProfile(const UserId& id) const override {
            std::cout << "Getting the user profile from the cache" << std::endl;
            return UserProfile();
        }    
};

class UserProfileStorageFactory {
    public:
        std::unique_ptr<UserProfileStorage> create() const {
            return std::make_unique<UserProfileCache>();
        }
        
};

void getUserProfile(const UserProfileStorageFactory& storageFactory) {
    std::unique_ptr<UserProfileStorage> storage = storageFactory.create();
    UserId user;
    storage->getUserProfile(user);
}

int main() {
    UserProfileStorageFactory factory;
    getUserProfile(factory);
}