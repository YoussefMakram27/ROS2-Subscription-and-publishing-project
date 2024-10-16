import rclpy
from rclpy.node import Node
from example_interfaces.msg import Int64

class number_counter(Node):
    def __init__(self):
        super().__init__('number_counter')
        self.counter_ = 0
        self.get_logger().info('Subscribtion has been started!!')
        self.publisher_ = self.create_publisher(Int64, "number_count", 10)
        self.subscriber_ = self.create_subscription(Int64, "number", self.callbacknumber, 10)
        
    
    def callbacknumber(self, msg):
        
        self.counter_ += 2
        new_msg = Int64()
        new_msg.data = self.counter_ 
        #self.get_logger().info(f'Recieved: {msg.data}, After addition: {new_msg.data}')
        '''
        important note:
        get_logger fucntion expext string message, it doesn't deal with other type
        so while your are here publishing integar, you have to convert it to string or it will crush
        '''
        self.publisher_.publish(new_msg)
        
            

def main(args = None):
    rclpy.init(args=args)
    node = number_counter()
    rclpy.spin(node)
    rclpy.shutdown()
    
    
if __name__ == '__main__':
    main()    
    