from collections import defaultdict, OrderedDict

class LFUCache:

    def __init__(self, capacity: int):

        self.capacity = capacity
        self.minFreq = 0

        # key -> [value, freq]
        self.key_to_val_freq = {}

        # freq -> ordered dict of keys
        self.freq_to_keys = defaultdict(OrderedDict)


    def updateFreq(self, key):

        value, freq = self.key_to_val_freq[key]

        # remove from old freq list
        del self.freq_to_keys[freq][key]

        # if this freq becomes empty
        if not self.freq_to_keys[freq]:

            del self.freq_to_keys[freq]

            if self.minFreq == freq:
                self.minFreq += 1

        # add to next freq
        self.key_to_val_freq[key] = [value, freq + 1]

        self.freq_to_keys[freq + 1][key] = None


    def get(self, key: int) -> int:

        if key not in self.key_to_val_freq:
            return -1

        value, freq = self.key_to_val_freq[key]

        self.updateFreq(key)

        return value


    def put(self, key: int, value: int) -> None:

        if self.capacity == 0:
            return

        # key already exists
        if key in self.key_to_val_freq:

            self.key_to_val_freq[key][0] = value

            self.updateFreq(key)

            return

        # cache full
        if len(self.key_to_val_freq) == self.capacity:

            # remove LFU + LRU
            lfu_key, _ = self.freq_to_keys[self.minFreq].popitem(last=False)

            del self.key_to_val_freq[lfu_key]

            if not self.freq_to_keys[self.minFreq]:
                del self.freq_to_keys[self.minFreq]

        # insert new key
        self.key_to_val_freq[key] = [value, 1]

        self.freq_to_keys[1][key] = None

        self.minFreq = 1