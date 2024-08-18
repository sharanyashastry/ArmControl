#include <iostream>
#include <Eigen/Dense>

// class AbstractRobot{
//     virtual double get_position() const  = 0;
// };

class Joint {
    public: 
        enum class Type{PRISMATIC, REVOLUTE};

        // Constructor
        Joint(Type type, double position):type_(type), position_(position){}

        // setters
        void set_position(double position){position_ = position;}

        // getters
        double get_position() const {return position_;}
        Type get_type() const {return type_;}

    private:
        Type type_;
        double position_ = 0;
};

class Link {
    public:
        Link(double length):length_(length){}

        double get_position() const {return length_;}
    private: 
        double length_;
};

class KinematicChain{
    public:
        KinematicChain(const std::vector<Joint>& joints, const std::vector<Link>& links):joints_(joints), links_(links){}
        // Getters
        std::vector<double> get_joint_positions() const;
        // Setters
        void set_joint_positions(const std::vector<double>& q_vector){}

        // Expansion methods
        void add_joint(const Joint& joint){joints_.push_back(joint);};
        void add_link(const Link& link){links_.push_back(link);}

        // Methods
        // FK that returns position of the EE.
        Eigen::Vector3d PositionFK(){}

    private:
        std::vector<Joint> joints_;
        std::vector<Link> links_;
};

