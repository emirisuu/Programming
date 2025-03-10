class Recording:
    def __init__(self, length):
        if length > 0:
            self.__length = length
        else:
            raise ValueError()

    @property
    def length(self):
        return self.__length
    
    @length.setter
    def length(self, len):
        if len > 0:
            self.__length = len
        else:
            raise ValueError()