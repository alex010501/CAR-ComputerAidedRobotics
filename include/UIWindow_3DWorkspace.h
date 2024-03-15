#pragma once

#include <MathAdditions.h>
#include <UI/UIWindow.h>
#include <UI/UIGraph.h>
#include <3D/BaseScene.h>
#include <random>
#include <math.h>

/*class randSignal {
private:
    double a, b, c;
    double f1, f2, f3;

    template <typename T>
    T getRand(T lower_bound, T upper_bound)
    {
        static std::random_device rd;
        static std::mt19937 gen(rd());

        if constexpr (std::is_integral_v<T>)
        {
            // For integral types (int, long, etc.)
            std::uniform_int_distribution<T> dist(lower_bound, upper_bound);
            return dist(gen);
        }
        else if constexpr (std::is_floating_point_v<T>)
        {
            // For floating-point types (float, double, etc.)
            std::uniform_real_distribution<T> dist(lower_bound, upper_bound);
            return dist(gen);
        }
        else
        {
            // Unsupported type
            throw std::invalid_argument("Unsupported type for getRand");
        }
    }

public:
    randSignal()
    {
        // Initialize random coefficients
        this->a = this->getRand(-1.0, 1.0);
        this->b = this->getRand(-1.0, 1.0);
        this->c = this->getRand(-1.0, 1.0);
        // Initialize random frequencies
        int k1 = this->getRand(1, 5);
        int k2 = this->getRand(1, 5);
        int k3 = this->getRand(1, 5);
        this->f1 = k1 * M_PI / 2;
        this->f2 = k2 * M_PI / 2;
        this->f3 = k3 * M_PI / 2;
    }

    double get_signal(double t)
    {
        double firstHarmonic = this->a * sin(this->f1 * t);
        double secondHarmonic = this->b * sin(this->f2 * t);
        double thirdHarmonic = this->c * sin(this->f3 * t);
        // std::cout << "Time " << t << std::endl;
        // std::cout << firstHarmonic << " " << secondHarmonic << " " << thirdHarmonic << std::endl;
        return firstHarmonic + secondHarmonic + thirdHarmonic;
    }
};*/

class UIWindow_3DWorkSpace: public UIWindow {
private:
    // Add variables here
    BaseScene* m_scene;

    MathAdditions::randSignal Q1, Q2, Q3;
    double m_dt;
    double m_time;

    MathAdditions::Derivator derivator;
    MathAdditions::Integrator integrator;
public:
    // Add variables here
    double q1, q2, q3;

    Graph graph_Q1, graph_Q2, graph_Q3;    

    // Add signals here
    sigslot::signal1<Graph*> signal_addGraph;

    // Add class methods here
    UIWindow_3DWorkSpace(const char* p_title);
    void init();
    void loadScene(BaseScene* p_scene);
    void draw();
    void update();
    void shutdown();
    void startSimulation(double p_dt, double p_duration);
    void resetSimulation();
};