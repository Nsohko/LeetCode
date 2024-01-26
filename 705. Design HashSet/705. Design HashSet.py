class MyHashSet(object):

    def __init__(self):

      # in python set and dictionaries are basic hashtables
        self.hashtable = set()
        

    def add(self, key):
        """
        :type key: int
        :rtype: None
        """
        self.hashtable.add(key)

    def remove(self, key):
        """
        :type key: int
        :rtype: None
        """
        if key in self.hashtable:
            self.hashtable.remove(key)

    def contains(self, key):
        """
        :type key: int
        :rtype: bool
        """
        if key in self.hashtable:
            return True
        else:
            return False
        


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)
