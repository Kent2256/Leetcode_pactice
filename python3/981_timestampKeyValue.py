
class TimeMap:

    def __init__(self):
        self.data = []

    def set(self, key: str, value: str, timestamp: int) -> None:
        if not self.data:
            for _ in range(timestamp):
                self.data.append(dict())
            self.data[-1][key] = value
            return
        if len(self.data) < timestamp:
            for _ in range(len(self.data),timestamp,1):
                self.data.append(self.data[-1].copy())
            self.data[-1][key] = value
            return
        self.data[timestamp - 1][key] = value

    def get(self, key: str, timestamp: int) -> str:
        if timestamp > len(self.data):
            return self.data[-1][key]
        else:
            return self.data[timestamp - 1][key]


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)

if __name__ == "__main__":
    timemap = TimeMap()
    timemap.set("foo", "bar", 10)
    print(timemap.data)
    timemap.set("foo", "bar2",20)
    print(timemap.data)