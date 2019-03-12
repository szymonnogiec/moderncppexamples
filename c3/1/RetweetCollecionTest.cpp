#include <gmock/gmock.h>
#include "Tweet.h"
#include "RetweetCollection.h"

using namespace testing;

class ARetweetCollection : public Test
{
public:
    RetweetCollection collection;
};

TEST_F(ARetweetCollection, IsEmptyWhenCreated)
{
    ASSERT_TRUE(collection.isEmpty());
}

TEST_F(ARetweetCollection, HasSizeZeroWhenCreated)
{
    ASSERT_THAT(collection.size(), Eq(0u));
}

TEST_F(ARetweetCollection, IsNoLongerEmptyAfterTweetAdded)
{
    collection.add(Tweet());
    ASSERT_FALSE(collection.isEmpty());
}

TEST_F(ARetweetCollection, DecreasesSizeAfterRemovingTweet)
{
    collection.add(Tweet());

}