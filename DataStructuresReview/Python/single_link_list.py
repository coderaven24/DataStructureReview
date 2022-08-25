from interfaces import ISingleLinkList


class Node :
    def __init__(self,obj,next):
        self.datum = obj
        self.next = next

class SingleLinkList(ISingleLinkList):
    def __init__(self):
        self.__head = None
        self.__tail = None
        self.__size = 0

    def prepend(self,obj):
        self.__head  = Node(obj,self.__head);

        if(self.__tail == None) :
            self.__tail = self.__head;

        ++self.__size

    def append(self,obj):
        tmp = Node(obj,None)

        if (self.__head != None) :
            self.__tail.next = tmp

        else :
            self.__head = tmp

        self.__tail = tmp
        ++self.__size

    def clear(self):
        self.__head = None
        self.__tail = None
        self.__size = 0

    def first(self):
        return self.__head.datum;

    def last(self):
        return

    def insert_after(self,obj,after):
        return

    def insert_before(self,obj,before):
        return

    def is_empty(self):
        return self.__size == 0

    def remove(self,obj):
        return

    def get_size(self):
        return self.__size

    def test(self) :
        print("SingleLinkList______________________")
        print("is empty : ", self.is_empty())
        print("adding letters a thru m to the list")
        self.append('a')
        self.append('b')
        self.append('c')
        self.append('d')
        self.append('e')
        self.append('f')
        self.append('g')
        self.append('h')
        self.append('i')
        self.append('j')
        self.append('k')
        self.append('n')
        self.append('m')
        self.test_output_contents()   
        print("is empty : ", self.is_empty());
        print("adding a 'y' to the front | ");
        self.prepend('y');
        self.test_output_contents();
        print("removing e | ");
        self.remove('e');
        self.test_output_contents();
        print("removing m | ");
        self.remove('m');
        self.test_output_contents();
        print("adding z before f | ");
        self.insert_before('z', 'f');
        self.test_output_contents();
        print("adding q after z | ");
        self.insert_after('q', 'z');
        self.test_output_contents();
        print("SingleLinkList______________________");        

    def test_output_contents(self):
        print("count: ",self.get_size())
        runner = self.__head

        while(runner != None) :
            print(runner.datum, end =" "),
            runner = runner.next

        print('\n')
