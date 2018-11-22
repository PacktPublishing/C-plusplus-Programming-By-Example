#include <iostream>
#include <random>
#include <string>

struct player
{
    std::string name;
    int total_money{ 0 };
};

struct wager_result
{
    bool did_win = false;
    int money_change_amount{ 0 };
    int wager{ 0 };
    int guess{ 0 };
};
std::ostream& operator<<(std::ostream& output, const wager_result &wager)
{
    output << "You bet " << std::to_string(wager.wager) << " and guessed "
        << std::to_string(wager.guess) << std::endl;
    output << "You ";
    if(wager.did_win)
    {
        output << "won ";
    }
    else
    {
        output << "lost ";
    }
    output << std::to_string(std::abs(wager.money_change_amount)) << std::endl;
    return output;
}

class number_generator
{
public:
    number_generator(const int &min, const int &max)
        : random_engine_(random_device_()), uniform_int_distribution_(min, max)
    {

    }
    int generate_random_number()
    {
        return uniform_int_distribution_(random_engine_);
    }
private:
    std::random_device random_device_;
    std::default_random_engine random_engine_;
    std::uniform_int_distribution<int> uniform_int_distribution_;
};

class game
{
    player player_;
    number_generator number_generator_;
public:
    game(const player& player)
        :number_generator_(1, 10)
    {
        player_ = player;
    }

    void start_game()
    {
        std::cout << "Enter your name: ";
        std::getline(std::cin, player_.name);
        std::cout << "Enter start money amount: ";
        std::cin >> player_.total_money;
    }

    bool keep_playing()
    {
        std::cout << "Play again? (Y/N): ";
        char response;
        std::cin >> response;
        return response == 'y' || response == 'Y';
    }

    int get_bet_amount()
    {
        std::cout << "Enter bet amount (1 - " +
            std::to_string(player_.total_money) + "): ";
        int wager;
        std::cin >> wager;
        return wager;
    }
    
    int get_guess()
    {
        std::cin.get();
        std::cout << "Enter guess (1-10): ";
        int guess;
        std::cin >> guess;
        return guess;
    }
    wager_result play_round()
    {
        const auto wager = get_bet_amount();
        const auto guess = get_guess();

        wager_result result;
        result.wager = wager;
        result.guess = guess;
        const auto number = number_generator_.generate_random_number();
        if(number == guess)
        {
            result.did_win = true;
            result.money_change_amount = wager * 10;
        }
        else
        {
            result.did_win = false;
            result.money_change_amount = -1 * wager;
        }

        player_.total_money += result.money_change_amount;
        return result;
    }

    bool game_over()
    {
        return player_.total_money <= 0;
    }
};

int main()
{
    std::cout << "----- Casino! -----" << std::endl;
    const player m_player;
    game game(m_player);
    game.start_game();
    do
    {
        const auto result = game.play_round();
        std::cout << result << std::endl;
        if (game.game_over()) {
            std::cout << "You lost, game over" << std::endl;
            break;
        }

    } while (!game.game_over() && game.keep_playing());

    std::cout << "Game over! Thanks for playing!" << std::endl;
    return 0;
}