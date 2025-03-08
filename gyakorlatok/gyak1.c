#include <stdio.h>
#include <stdlib.h>

typedef struct{
  float length;
  float width;
  float height;
}Cuboid;

void set_size(Cuboid* cuboid, float length, float width, float height) {
    if (length > 0 && width > 0 && height > 0) {
        cuboid->length = length;
        cuboid->width = width;
        cuboid->height = height;
    } else {
        printf("Hiba: A mereteknek pozitiv szamoknak kell lenniük!\n");
    }
}

float calc_volume(Cuboid cuboid) {
    return cuboid.length * cuboid.width * cuboid.height;
}

float calc_surface(Cuboid cuboid) {
    return 2 * (cuboid.length * cuboid.width + cuboid.length * cuboid.height + cuboid.width * cuboid.height);
}

int has_square_face(Cuboid cuboid) {
    if (cuboid.length == cuboid.width || cuboid.length == cuboid.height || cuboid.width == cuboid.height) {
        return 1; // Van négyzet alakú lap
    }
    return 0; // Nincs
}

int main() {
    Cuboid cuboid;

    // Beállítjuk a méreteket
    set_size(&cuboid, 4.0, 3.0, 2.0);

    // Térfogat és felszín számítása
    printf("Terfogat: %.2f\n", calc_volume(cuboid));
    printf("Felszin: %.2f\n", calc_surface(cuboid));

    // Ellenőrizzük, hogy van-e négyzet alakú lap
    if (has_square_face(cuboid)) {
        printf("A teglatestnek van negyzet alaku lapja.\n");
    } else {
        printf("A teglatestnek nincs negyzet alaku lapja.\n");
    }

    return 0;
}
