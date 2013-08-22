/*
Copyright (C) 2012 Kolibre

This file is part of kolibre-player.

Kolibre-player is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 2.1 of the License, or
(at your option) any later version.

Kolibre-player is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with kolibre-player. If not, see <http://www.gnu.org/licenses/>.
*/

#include <cstdlib>
#include <Player.h>

#include "data.h"
#include "setup_logging.h"
#include <boost/bind.hpp>

using namespace std;


int main(int argc, char *argv[])
{
    setup_logging();

    Player *player = Player::Instance();

    assert(player->getTempo() == 1);
    assert(player->getState() == INACTIVE);

    player->enable(NULL,NULL);

    player->setTempo(1.2);
    sleep(1);
    assert(player->getTempo() == 1.2);

    player->setState(EXITING);
    sleep(1);

    player = Player::Instance();
    assert(player->getState() == STOPPED);
    assert(player->getTempo() == 1.2);

    //Open a bogus to make player go to exiting;
    player->open("alban");
    sleep(1);
    assert(player->getState() == EXITING);

    player = Player::Instance();
    assert(player->getState() == STOPPED);
    assert(player->getTempo() == 1.2);

}
