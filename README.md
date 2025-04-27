
# Sailing Adventure

## Leírás
Ez a projekt egy 3D-s szimuláció, amelyben egy hajó mozog egy hullámzó vízfelületen. A program célja, hogy bemutassa az alapvető számítógépes grafikai technikákat, mint például:
- 3D modellek betöltése és renderelése
- Textúrázás
- Animált vízfelület használata
- Fények és árnyékok alkalmazása
- Egyszerű szél- és hajó mozgás szimuláció

A projekt C nyelven készült OpenGL használatával.

---

## Követelmények

A projekt futtatásához szükséges könyvtárak:
- C fordító (pl. GCC, MinGW)
- GLFW (ablakkezelés)
- GLAD (OpenGL loader)
- stb_image.h (képfájl betöltéshez)

A szükséges könyvtárak megtalálhatók a projekt mappáiban.

---

## Fordítás

A projekt lefordítása a `make` segítségével történik:

```bash
make
```

Ez létrehoz egy futtatható állományt.

---

## Használat

A program indítása a következőképpen történik:

```bash
./sailing
```

Vezérlés:
- **W, A, S, D** – Kamera mozgatása
- **Egér** – Kamera forgatása
- **Bal egérgomb** – Hajó irányítása
- **Q, E** – Szélirány változtatása
- **ESC** – Kilépés a programból
- **F1** – Segítség megjelenítése

---

## Funkciók

- [x] Kamera szabad mozgatása
- [x] Hullámzó víz shader
- [x] Hajó modell betöltése
- [x] Textúrák alkalmazása
- [x] Fények hozzáadása
- [x] Szélirány módosítása
- [ ] Hajó dőlésének szimulációja szélben (tervezett)
- [ ] Részecskerendszer (vízfröccsenés) (tervezett)

---

## Licenc

Ez a projekt oktatási célokra készült.

---

### Jegyzet
> A README folyamatosan frissülhet, ahogy új funkciók kerülnek implementálásra!
