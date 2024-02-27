# ComputerAidedRobotics

## What is it? | Что это?

This is prototype of my Master Science work **Computer Aided Robotics - CAR**

Это прототип моей магистерской работы **Computer Aided Robotics - CAR**

## Aim of the project | Цель проекта

The main target of Master project is creating tool for ***real-time computer robotic simulation*** with simulation of ***robot dynamics***.

The next step of the project is to design and train upper and lower level controllers based on a ***neural network*** for use in an industrial robot manipulator.

Главной задачей магистерской работы является создания инструмента для ***компьютерного моделирования промышленных роботов в реальном времени*** с учетом ***динамических характеристик роботов***.

Следующий шагом развития данного проекта - разработка и обучение контроллеров верхнего и нижнего уровней на основе ***нейронных сетей*** для использования в роботах-манипуляторах.

## Used external libraries | Используемые внешние библиотеки

* **Eigen** - library for linear algebra and matrix operations | библиотека для линейной алгебры и матричных операций;
* **GLAD** - OpenGL loader | библиотека для загрузки OpenGL;
* **GLFW** - OpenGL window | оконная система OpenGL;
* **GLM** - OpenGL math | математические функции OpenGL;
* **Assimp** - 3D model loading | библиотека для загрузки 3D модели;
* **Bullet** - physics engine | библиотека для работы с физическим движением;
* **ImGui** - user interface | пользовательский интерфейс приложения;


## Requirements for building | Требования для сборки

* **CMake 3.13 or later**
* **Clang 16.0.5 or later**
* **OpenGL 3.3 or later**
* **VSCode with CMake Tools Extension**

## Download and building | Скачивание и сборка
```bash
git clone https://github.com/alex010501/CAR-ComputerAidedRobotics.git
cd CAR-ComputerAidedRobotics
cmake -S. -Bbuild # $CMakeOptions
cmake --build build
```
