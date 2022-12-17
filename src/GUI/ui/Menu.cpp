#include <GUI/ui/Menu.hpp>

using namespace ::gui;

// Constructor
// The constructor just creates the objects  
Menu::Menu() {
    // Creating the objects
    window = new sf::RenderWindow();
    winclose = new sf::RectangleShape();
    font = new sf::Font();
    image = new sf::Texture();
    bg = new sf::Sprite();

    set_values();
}

// Destructor
Menu::~Menu() {
    delete window;
    delete winclose;
    delete font;
    delete image;
    delete bg;
}

void Menu::set_values() {
    // Creating a window 1280 x 720 
    window->create(sf::VideoMode(1280, 720), "Menu SFML", sf::Style::Titlebar | sf::Style::Close);
    // The mouse is at 0,0
    window->setPosition(sf::Vector2i(0, 0));

    pos = 0;
    pressed = theselect = false;
    font->loadFromFile("./src/GUI/Sheets/Menu/font/ethn.otf");
    image->loadFromFile("./src/GUI/Sheets/Menu/img/menu-play.png");

    bg->setTexture(*image);

    pos_mouse = { 0,0 };
    mouse_coord = { 0, 0 };

    // The different containers are linked by the id. option[0] refeeres to coords[0] refeers to size[0]
    options = { "War Game", "Play", "Options", "About", "Quit" };
    texts.resize(5);
    coords = { {460,100},{200,213},{188,295},{200,370},{220,447} };
    sizes = { 50,28,24,24,24 };

    for (std::size_t i{}; i < texts.size(); ++i) {
        texts[i].setFont(*font);
        texts[i].setString(options[i]);
        texts[i].setCharacterSize(sizes[i]);
        texts[i].setOutlineColor(sf::Color::Black);
        texts[i].setPosition(coords[i]);
    }
    texts[1].setOutlineThickness(4);
    pos = 1;

    winclose->setSize(sf::Vector2f(23, 26));
    winclose->setPosition(1178, 39);
    winclose->setFillColor(sf::Color::Transparent);

}



void Menu::loop_events() {
    std::string path;
    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }

        pos_mouse = sf::Mouse::getPosition(*window);
        mouse_coord = window->mapPixelToCoords(pos_mouse);


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed) {
            if (pos < 4) {
                ++pos;
                pressed = true;
                texts[pos].setOutlineThickness(4);
                texts[pos - 1].setOutlineThickness(0);
                pressed = false;
                theselect = false;
                path = options[pos];
                image->loadFromFile("./src/GUI/Sheets/Menu/img/menu-" + path + ".png");

            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed) {
            if (pos > 1) {
                --pos;
                pressed = true;
                texts[pos].setOutlineThickness(4);
                texts[pos + 1].setOutlineThickness(0);
                pressed = false;
                theselect = false;
                path = options[pos];
                image->loadFromFile("./src/GUI/Sheets/Menu/img/menu-" + path + ".png");
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect) {
            theselect = true;
            if (pos == 4) {
                window->close();
            }
            std::cout << options[pos] << '\n';
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (winclose->getGlobalBounds().contains(mouse_coord)) {
                //std::cout << "Close the window!" << '\n';
                window->close();
            }
        }
    }
}

void Menu::draw_all() {
    window->clear();
    window->draw(*bg);
    for (auto t : texts) {
        window->draw(t);
    }
    window->display();
}

void Menu::run_menu() {
    while (window->isOpen()) {
        loop_events();
        draw_all();
    }
}