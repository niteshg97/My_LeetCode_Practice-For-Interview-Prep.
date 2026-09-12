import heapq
class Twitter:
    def __init__(self):
        self.tweets = {}       # userId -> list of (time, tweetId)
        self.following = {}    # userId -> set of users they follow
        self.time = 0
    def postTweet(self, userId: int, tweetId: int) -> None:

        if userId not in self.tweets:
            self.tweets[userId] = []

        self.tweets[userId].append((self.time, tweetId))
        self.time += 1

    def getNewsFeed(self, userId: int) -> List[int]:

        heap = []
        # Include user's own tweets
        if userId in self.tweets:
            for time, tweetId in self.tweets[userId]:
                heapq.heappush(heap, (-time, tweetId))
        # Include tweets from followed users
        if userId in self.following:
            for followeeId in self.following[userId]:

                if followeeId in self.tweets:
                    for time, tweetId in self.tweets[followeeId]:
                        heapq.heappush(heap, (-time, tweetId))

        # Get 10 most recent tweets
        feed = []

        while heap and len(feed) < 10:
            time, tweetId = heapq.heappop(heap)
            feed.append(tweetId)

        return feed

    def follow(self, followerId: int, followeeId: int) -> None:

        if followerId not in self.following:
            self.following[followerId] = set()

        self.following[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:

        if followerId in self.following:
            self.following[followerId].discard(followeeId)
        


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)