class Node:
    def __init__(self,data):
        self.item=data
        self.next=None
class LinkedList:
    def __init__(self):
        self.head=None
    def traverselist(self):
        if self.head is None:
          print("List has no elements")
          return
        else:
          q=self.head
          while q is not None:
            print(q.item," ")
            q=q.next
    def insertion_beg(self,data):
        temp=Node(data)
        temp.next=self.head
        self.head=temp
new_linkedlist=LinkedList()
new_linkedlist.insertion_beg(5)
new_linkedlist.insertion_beg(10)
new_linkedlist.insertion_beg(15)
new_linkedlist.traverselist()

            
