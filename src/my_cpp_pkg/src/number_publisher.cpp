#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int64.hpp"

class number_publisher : public rclcpp::Node
{
    public:
        number_publisher() : Node("number_publisher")
        {
            publisher_ = this->create_publisher<example_interfaces::msg::Int64>("number", 10);
            timer_ = this->create_wall_timer(std::chrono::milliseconds(500),
                                             std::bind(&number_publisher::callbacknumber, this));
            RCLCPP_INFO(this->get_logger(), "Publishing Number has been started!!");
        }r

    private:
        void callbacknumber()
        {
            auto msg = example_interfaces::msg::Int64();
            msg.data = 38;
            publisher_->publish(msg);
        }
        rclcpp::Publisher<example_interfaces::msg::Int64>::SharedPtr publisher_;
        rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<number_publisher>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}