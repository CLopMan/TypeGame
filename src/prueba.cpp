#include <iostream>
#include <thread> 
#include <string>
#include <curses.h>

int main() {
    // Iniciar el modo ncurses
    initscr();

    // Crear una nueva ventana
    WINDOW *ventana;
    int altura = 10, ancho = 30, inicioY = 2, inicioX = 4;
    ventana = newwin(altura, ancho, inicioY, inicioX);

    // Imprimir en la ventana

    // Actualizar la ventana
    wrefresh(ventana);
    mvwprintw(ventana, 1, 1, "¡Hello!");
    // Esperar a que el usuario presione una tecla
    char c = getch();
    wrefresh(ventana);
    mvwprintw(ventana, 0, 0, "usted ha escrito\n");
    wrefresh(ventana);

    c = getch();

    // Limpiar y cerrar el modo ncurses
    endwin();

    return 0;
}
