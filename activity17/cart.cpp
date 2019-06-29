#include <iostream>
#include <vector>
#include <string>

struct UserIdentifier {
    int userId = 0;
};

struct Item {
    int id = 0;
};

bool operator==(const Item& lhs, const Item& rhs) {
    return lhs.id == rhs.id;
}

struct Cart {
    std::vector<Item> items;
};

bool isLoggedIn(const UserIdentifier& user) {
    return (user.userId % 2) == 0;
}

Cart getUserCart(const UserIdentifier& user) {
    return Cart();
}

void removeItem(Cart& cart, Item cartItem) {
    auto location = std::find(cart.items.begin(), cart.items.end(), cartItem);

    if (location != cart.items.end()) {
        cart.items.erase(location);
    }

    std::cout << "Item Removed" << std::endl;
}

void addItems(Cart& cart, std::vector<Item> items) {
    cart.items.insert(cart.items.end(), items.begin(), items.end());
    std::cout << "Item added" << std::endl;
}

template<typename Action, typename Parameter>
void execute_on_user_cart(UserIdentifier user, Action action, Parameter&& parameter) {
    if (isLoggedIn(user)) {
        Cart cart = getUserCart(user);
        action(cart, std::forward<Parameter>(parameter));
    }
    else {
        std::cout << "The user is not logged in" << std::endl;
    }
}

int main() {
    Item toothbrush{1023};
    Item toothpaste{1024};

    UserIdentifier loggedInUser{0};

    std::cout << "Adding items if the user is logged in" << std::endl;
    
    execute_on_user_cart(loggedInUser, addItems, std::vector<Item>({toothbrush, toothpaste}));

    UserIdentifier loggedOutUser{1};
    std::cout << "Removing item if the user is logged in" << std::endl;
    execute_on_user_cart(loggedOutUser, removeItem, toothbrush);

}
