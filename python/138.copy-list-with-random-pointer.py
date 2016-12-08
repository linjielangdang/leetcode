# Definition for singly-linked list with a random pointer.
# class RandomListNode(object):
#     def __init__(self, x):
#         self.label = x
#         self.next = None
#         self.random = None

class Solution:
    # @param head: A RandomListNode
    # @return: A RandomListNode
    def copyRandomList(self, head):
        dummy = RandomListNode(0)
        curNode = dummy
        hash_map = {}

        while head is not None:
            # link newNode to new List
            if head in hash_map.keys():
                newNode = hash_map[head]
            else:
                newNode = RandomListNode(head.label)
                hash_map[head] = newNode
            curNode.next = newNode
            # copy old node random pointer
            if head.random is not None:
                if head.random in hash_map.keys():
                    newNode.random = hash_map[head.random]
                else:
                    newNode.random = RandomListNode(head.random.label)
                    hash_map[head.random] = newNode.random
            head = head.next
            curNode = curNode.next

        return dummy.next
