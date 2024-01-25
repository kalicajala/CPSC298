// @file ElectronicControlUnit.cpp
// @brief Midterm Programming Assignment
// @author Kali Cajala

#include <iostream>

class ElectronicControlUnit {
    public: 
        ElectronicControlUnit() : m_bActivatedHydraulicJacks(false), m_bActivatedBeltTires(false), m_bActivatedIRIllumination(false) {}
        ~ElectronicControlUnit();
        void handleCommand(char cCommand);

    private:
        bool m_bActivatedHydraulicJacks; // Button A
        bool m_bActivatedBeltTires; // Button B
        bool m_bActivatedIRIllumination; // Button E
        void activateHydraulicJacks() {
            m_bActivatedHydraulicJacks = !m_bActivatedHydraulicJacks;
            std::cout << "Hydraulic Jacks " << (m_bActivatedHydraulicJacks ? "activated" : "deactivated") << std::endl;
        }
        void activateBeltTires() {
            m_bActivatedBeltTires = !m_bActivatedBeltTires;
            std::cout << "Belt Tires " << (m_bActivatedBeltTires ? "activated" : "deactivated") << std::endl;
        }
        void activateIRIllumination() {
            m_bActivatedIRIllumination = !m_bActivatedIRIllumination;
            std::cout << "Infrared Illumination " << (m_bActivatedIRIllumination ? "activated" : "deactivated") << std::endl;
        }
        
};



ElectronicControlUnit::~ElectronicControlUnit(){
}

void ElectronicControlUnit::handleCommand(char cCommand) {
    switch (cCommand) {
        case 'A':
        case 'a':
            activateHydraulicJacks();
            break;
        case 'B':
        case 'b':
            activateBeltTires();
            break;
        case 'E':
        case 'e':
            activateIRIllumination();
            break;
        case 'X':
        case 'x':
            exit(0);
    }
}

int main() {
    ElectronicControlUnit ecu;
    char input;

    std::cout << "Press X to turn off the ignition or enter a steering wheel button (A, B, or E)" << std::endl;

    while(true){
        std::cout << "        (A)        " << std::endl;
        std::cout << "    (F) (G) (B)    " << std::endl;
        std::cout << "    (E)     (C)    " << std::endl;
        std::cout << "        (D)        " << std::endl;
        
        std::cin >> input;

        ecu.handleCommand(input);
    }
    return 0;
}