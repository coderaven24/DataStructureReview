from asyncio.windows_events import NULL
from interfaces import ISingleLinkList


class SingleLinkListNode :
    def __init__(self,datum,next):
        self.datum = datum
        self.next = next
        
    




class SingleLinkList(ISingleLinkList):
    def __init__(self):
        self.head = NULL
        self.tail = NULL
        self.size = 0

    def prepend(self,x):
        return 0

    def append(self,x):
        return 0

    def clear(self):
        return 0

    def first(self):
        return 0

    def last(self):
        return 0

    def insertAfter(self,x,after):
        return 0

    def insertBefore(self,x,before):
        return 0

    def isEmpty(self):
        return 0

    def remove(self,x):
        return 0

    def size(self):
        return 0

    def test(self) :
        print("SingleLinkList______________________")
        print("is empty : ", type(self.isEmpty()))
        print("adding letters a thru m to the list")

    def testOutputContents(self):
        print("count: ",type(self.size()))
        runner = self.head

        while(runner != NULL) :
            print(runner.datum, " ")
            runner = runner.next

        print('\n')