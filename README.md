# particles

Implements particle systems using openGL

## How to build

*Windows*

Open git bash to the directory containing this repository.

```
particles $ mkdir build
particles $ cd build
particles/build $ cmake -G "Visual Studio 16 2019" ..
particles/build $ start CS312-Particles.sln
```

Your solution file should contain two projects: `pixmap_art` and `pixmap_test`.
To run from the git bash command shell, 

```
particles/build $ ../bin/Debug/billboard
particles/build $ ../bin/Debug/confetti
particles/build $ ../bin/Debug/demo
```

*macOS*

Open terminal to the directory containing this repository.

```
particles $ mkdir build
particles $ cd build
particles/build $ cmake ..
particles/build $ make
```

To run each program from build, you would type

```
particles/build $ ../bin/billboard
particles/build $ ../bin/confetti
particles/build $ ../bin/demo
```

## Results

For unique demo, I have implemented a firework-ish feature without trailing effect ( ok I admit it looks more like confetti being thrown out and fall under gravity). To see it, run demo and there is a default location and color in the middle of screen. Click on the position in the window where you want the firework to originate. You can do this as many times as you want, the and color changes!
1. billboard:\
![alt text](https://github.com/JiangxueHan529/particles/blob/main/results/billboard.jpg)

2. confetti:\
![alt text](https://github.com/JiangxueHan529/particles/blob/main/results/confetti.jpg)

3. unique demo:\
 ![alt text](https://github.com/JiangxueHan529/particles/blob/main/results/demo.gif)
