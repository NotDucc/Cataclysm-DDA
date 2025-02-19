#pragma once
#ifndef CATA_SRC_HELP_H
#define CATA_SRC_HELP_H

#include <iosfwd>
#include <map>
#include <string>
#include <utility>
#include <vector>

class JsonIn;
class translation;
namespace catacurses
{
class window;
}  // namespace catacurses

class help
{
    public:
        void load();
        void display_help() const;

    private:
        void deserialize( JsonIn &jsin );
        void draw_menu( const catacurses::window &win ) const;
        static std::string get_note_colors();
        static std::string get_dir_grid();

        std::map<int, std::pair<translation, std::vector<translation>>> help_texts;
};

help &get_help();

std::string get_hint();

#endif // CATA_SRC_HELP_H
