#include <SFML/Graphics.hpp>
#include <vector>

int main()
{
    // =========================
    // VENTANA
    // =========================

    sf::RenderWindow window(
        sf::VideoMode(1000, 700),
        "PONG MENU"
    );

    window.setFramerateLimit(144);

    // =========================
    // FUENTE
    // =========================

    sf::Font font;

    if (!font.loadFromFile("font.ttf"))
    {
        return -1;
    }

    // =========================
    // TITULO
    // =========================

    sf::Text title;

    title.setFont(font);

    title.setString("PONG");

    title.setCharacterSize(90);

    title.setFillColor(sf::Color::White);

    title.setPosition(350.f, 80.f);

    // =========================
    // BOTON TRADICIONAL
    // =========================

    sf::RectangleShape traditionalButton(
        sf::Vector2f(470.f, 100.f)
    );

    traditionalButton.setPosition(300.f, 250.f);

    traditionalButton.setFillColor(
        sf::Color(70, 70, 70)
    );

    sf::Text traditionalText;

    traditionalText.setFont(font);

    traditionalText.setString("Tradicional");

    traditionalText.setCharacterSize(40);

    traditionalText.setFillColor(sf::Color::White);

    traditionalText.setPosition(325.f, 275.f);

    // =========================
    // BOTON BLOQUES
    // =========================

    sf::RectangleShape blocksButton(
        sf::Vector2f(470.f, 100.f)
    );

    blocksButton.setPosition(300.f, 420.f);

    blocksButton.setFillColor(
        sf::Color(70, 70, 70)
    );

    sf::Text blocksText;

    blocksText.setFont(font);

    blocksText.setString("Bloques");

    blocksText.setCharacterSize(40);

    blocksText.setFillColor(sf::Color::White);

    blocksText.setPosition(400.f, 445.f);

    // =========================
    // BUCLE PRINCIPAL
    // =========================

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            // =========================
            // CERRAR
            // =========================

            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            // =========================
            // CLICK MOUSE
            // =========================

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos =
                        sf::Mouse::getPosition(window);

                    // =========================
                    // BOTON TRADICIONAL
                    // =========================

                    if (
                        traditionalButton
                        .getGlobalBounds()
                        .contains(
                            (float)mousePos.x,
                            (float)mousePos.y
                        )
                    )
                    {// =========================
                        // VENTANA
                        // =========================

                        sf::RenderWindow window(
                            sf::VideoMode(1000, 700),
                            "PONG"
                        );

                        window.setFramerateLimit(144);

                        // =========================
                        // FUENTE
                        // =========================

                        sf::Font font;

                        if (!font.loadFromFile("font.ttf"))
                        {
                            return -1;
                        }

                        // =========================
                        // PUNTAJES
                        // =========================

                        int leftScore = 0;
                        int rightScore = 0;

                        sf::Text leftText;
                        sf::Text rightText;

                        leftText.setFont(font);
                        rightText.setFont(font);

                        leftText.setCharacterSize(60);
                        rightText.setCharacterSize(60);

                        leftText.setFillColor(sf::Color::White);
                        rightText.setFillColor(sf::Color::White);

                        leftText.setPosition(350.f, 20.f);
                        rightText.setPosition(600.f, 20.f);

                        // =========================
                        // PELOTA
                        // =========================

                        sf::CircleShape ball(10.f);

                        ball.setFillColor(sf::Color::White);

                        ball.setPosition(500.f, 350.f);

                        float initialBallSpeedX = 0.35f;
                        float initialBallSpeedY = 0.35f;

                        float ballSpeedX = initialBallSpeedX;
                        float ballSpeedY = initialBallSpeedY;

                        float maxBallSpeed = 1.8f;

                        // =========================
                        // JUGADOR IZQUIERDO
                        // =========================

                        sf::RectangleShape leftPaddle(
                            sf::Vector2f(20.f, 120.f)
                        );

                        leftPaddle.setFillColor(sf::Color::White);

                        leftPaddle.setPosition(40.f, 290.f);

                        // =========================
                        // JUGADOR DERECHO
                        // =========================

                        sf::RectangleShape rightPaddle(
                            sf::Vector2f(20.f, 120.f)
                        );

                        rightPaddle.setFillColor(sf::Color::White);

                        rightPaddle.setPosition(940.f, 290.f);

                        float paddleSpeed = 0.5f;

                        // =========================
                        // LINEA CENTRAL
                        // =========================

                        sf::RectangleShape centerLine(
                            sf::Vector2f(5.f, 700.f)
                        );

                        centerLine.setPosition(497.5f, 0.f);

                        centerLine.setFillColor(
                            sf::Color(100, 100, 100)
                        );

                        // =========================
                        // BUCLE PRINCIPAL
                        // =========================

                        while (window.isOpen())
                        {
                            // =========================
                            // EVENTOS
                            // =========================

                            sf::Event event;

                            while (window.pollEvent(event))
                            {
                                if (event.type == sf::Event::Closed)
                                {
                                    window.close();
                                }
                            }

                            // =========================
                            // ACTUALIZAR TEXTO
                            // =========================

                            leftText.setString(std::to_string(leftScore));
                            rightText.setString(std::to_string(rightScore));

                            // =========================
                            // CONTROLES
                            // =========================

                            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                            {
                                if (leftPaddle.getPosition().y > 0)
                                {
                                    leftPaddle.move(0.f, -paddleSpeed);
                                }
                            }

                            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                            {
                                if (leftPaddle.getPosition().y < 580)
                                {
                                    leftPaddle.move(0.f, paddleSpeed);
                                }
                            }

                            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                            {
                                if (rightPaddle.getPosition().y > 0)
                                {
                                    rightPaddle.move(0.f, -paddleSpeed);
                                }
                            }

                            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                            {
                                if (rightPaddle.getPosition().y < 580)
                                {
                                    rightPaddle.move(0.f, paddleSpeed);
                                }
                            }

                            // =========================
                            // MOVIMIENTO PELOTA
                            // =========================

                            ball.move(ballSpeedX, ballSpeedY);

                            // =========================
                            // REBOTE ARRIBA / ABAJO
                            // =========================

                            if (ball.getPosition().y <= 0)
                            {
                                ballSpeedY = std::abs(ballSpeedY);
                            }

                            if (ball.getPosition().y >= 680)
                            {
                                ballSpeedY = -std::abs(ballSpeedY);
                            }

                            // =========================
                            // COLISIONES
                            // =========================

                            float acceleration = 1.05f;

                            if (
                                ball.getGlobalBounds().intersects(
                                    leftPaddle.getGlobalBounds()
                                )
                            )
                            {
                                ballSpeedX = std::abs(ballSpeedX);

                                if (std::abs(ballSpeedX) < maxBallSpeed)
                                {
                                    ballSpeedX *= acceleration;
                                    ballSpeedY *= acceleration;
                                }
                            }

                            if (
                                ball.getGlobalBounds().intersects(
                                    rightPaddle.getGlobalBounds()
                                )
                            )
                            {
                                ballSpeedX = -std::abs(ballSpeedX);

                                if (std::abs(ballSpeedX) < maxBallSpeed)
                                {
                                    ballSpeedX *= acceleration;
                                    ballSpeedY *= acceleration;
                                }
                            }

                            // =========================
                            // PUNTOS
                            // =========================

                            // Punto jugador derecho

                             if (ball.getPosition().x < 0)
                            {
                                rightScore++;

                                ball.setPosition(500.f, 350.f);

                                ballSpeedX = std::abs(initialBallSpeedX);
                                ballSpeedY = initialBallSpeedY;
                            }

                            // Punto jugador izquierdo

                            if (ball.getPosition().x > 1000)
                            {
                                leftScore++;

                                ball.setPosition(500.f, 350.f);

                                ballSpeedX = -std::abs(initialBallSpeedX);
                                ballSpeedY = initialBallSpeedY;
                            }

                            // =========================
                            // DIBUJAR
                            // =========================

                            window.clear(sf::Color::Black);

                            window.draw(centerLine);

                            window.draw(leftPaddle);

                            window.draw(rightPaddle);

                            window.draw(ball);

                            window.draw(leftText);

                            window.draw(rightText);

                            window.display();
                        }
                    }

                    // =========================
                    // BOTON BLOQUES
                    // =========================

                    if (
                        blocksButton
                        .getGlobalBounds()
                        .contains(
                            (float)mousePos.x,
                            (float)mousePos.y
                        )
                    )
                    {
                        // =========================
                        // VENTANA
                        // =========================

                        sf::RenderWindow window(
                            sf::VideoMode(1000, 700),
                            "BREAKOUT"
                        );

                        window.setFramerateLimit(144);

                        

                        // =========================
                        // PELOTA
                        // =========================

                        sf::CircleShape ball(10.f);

                        ball.setFillColor(sf::Color::White);

                        ball.setPosition(500.f, 500.f);

                        float ballSpeedX = 0.4f;
                        float ballSpeedY = -0.4f;

                        // =========================
                        // BARRA JUGADOR
                        // =========================

                        sf::RectangleShape paddle(
                            sf::Vector2f(150.f, 20.f)
                        );

                        paddle.setFillColor(sf::Color::White);

                        paddle.setPosition(425.f, 650.f);

                        float paddleSpeed = 0.7f;

                        // =========================
                        // BLOQUES
                        // =========================

                        std::vector<sf::RectangleShape> blocks;

                        for (int row = 0; row < 5; row++)
                        {
                            for (int col = 0; col < 8; col++)
                            {
                                sf::RectangleShape block(
                                    sf::Vector2f(100.f, 30.f)
                                );

                                block.setPosition(
                                    70.f + col * 110.f,
                                    70.f + row * 40.f
                                );

                                block.setFillColor(
                                    sf::Color(
                                        100 + row * 25,
                                        50 + col * 20,
                                        200
                                    )
                                );

                                blocks.push_back(block);
                            }
                        }

                        // =========================
                        // BUCLE PRINCIPAL
                        // =========================

                        while (window.isOpen())
                        {
                            // =========================
                            // EVENTOS
                            // =========================

                            sf::Event event;

                            while (window.pollEvent(event))
                            {
                                if (event.type == sf::Event::Closed)
                                {
                                    window.close();
                                }
                            }

                            
                            // =========================
                            // MOVIMIENTO JUGADOR
                            // =========================

                            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                            {
                                if (paddle.getPosition().x > 0)
                                {
                                    paddle.move(-paddleSpeed, 0.f);
                                }
                            }

                            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                            {
                                if (paddle.getPosition().x < 850)
                                {
                                    paddle.move(paddleSpeed, 0.f);
                                }
                            }
// =========================
// MOVIMIENTO PELOTA
// =========================

ball.move(ballSpeedX, ballSpeedY);

// =========================
// REBOTE PAREDES
// =========================

// Pared izquierda

if (ball.getPosition().x <= 0)
{
    ballSpeedX = std::abs(ballSpeedX);
}

// Pared derecha

if (ball.getPosition().x >= 980)
{
    ballSpeedX = -std::abs(ballSpeedX);
}

// Pared superior

if (ball.getPosition().y <= 0)
{
    ballSpeedY = std::abs(ballSpeedY);
}

// =========================
// REBOTE BARRA
// =========================

if (
    ball.getGlobalBounds().intersects(
        paddle.getGlobalBounds()
    )
)
{
    ballSpeedY = -std::abs(ballSpeedY);
}
                            
 
// =========================
// COLISION BLOQUES
// =========================

for (int i = 0; i < blocks.size(); i++)
{
    if (
        ball.getGlobalBounds().intersects(
            blocks[i].getGlobalBounds()
        )
    )
    {
        // Rebote de la pelota

        ballSpeedY = -ballSpeedY;

        // Destruir bloque

        blocks.erase(blocks.begin() + i);

        // Evitar multiples colisiones
        // en el mismo frame

        break;
    }
}

                            // =========================
                            // DIBUJAR
                            // =========================

                            window.clear(sf::Color::Black);

                            // Dibujar bloques

                            for (auto& block : blocks)
                            {
                                window.draw(block);
                            }

                            // Dibujar elementos

                            window.draw(ball);

                            window.draw(paddle);

                            window.display();
                        }
                    }
                }
            }
        }

        // =========================
        // HOVER EFECTO
        // =========================

        sf::Vector2i mousePos =
            sf::Mouse::getPosition(window);

        // Hover Tradicional

        if (
            traditionalButton
            .getGlobalBounds()
            .contains(
                (float)mousePos.x,
                (float)mousePos.y
            )
        )
        {
            traditionalButton.setFillColor(
                sf::Color(120, 120, 120)
            );
        }
        else
        {
            traditionalButton.setFillColor(
                sf::Color(70, 70, 70)
            );
        }

        // Hover Bloques

        if (
            blocksButton
            .getGlobalBounds()
            .contains(
                (float)mousePos.x,
                (float)mousePos.y
            )
        )
        {
            blocksButton.setFillColor(
                sf::Color(120, 120, 120)
            );
        }
        else
        {
            blocksButton.setFillColor(
                sf::Color(70, 70, 70)
            );
        }

        // =========================
        // DIBUJAR
        // =========================

        window.clear(sf::Color::Black);

        window.draw(title);

        window.draw(traditionalButton);

        window.draw(traditionalText);

        window.draw(blocksButton);

        window.draw(blocksText);

        window.display();
    }

    return 0;
}