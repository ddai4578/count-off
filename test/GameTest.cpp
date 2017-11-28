#include "gtest/gtest.h"
#include "CountOffGame.h"

struct GameTest : testing::Test
{
    GameTest() : game_sprint_1_2({{3, "ʯͷ"},{5, "����"},{7, "��"}})
               , game_sprint_3({{5, "ʯͷ"},{7, "����"},{9, "��"}})
               , game_sprint_4({{3, "�ϻ�"},{5, "����"},{7, "��"}})
    {
    }

    void ASSERT_COUNTOFF_3_5_7(int n, const std::string& words)
    {
        ASSERT_COUNTOFF(game_sprint_1_2, n, words);
    }

    void ASSERT_COUNTOFF_5_7_9(int n, const std::string& words)
    {
        ASSERT_COUNTOFF(game_sprint_3, n, words);
    }

    void ASSERT_COUNTOFF_3_5_7_EX(int n, const std::string& words)
    {
        ASSERT_COUNTOFF(game_sprint_4, n, words);
    }

private:
    void ASSERT_COUNTOFF(const CountOffGame& game, int n, const std::string& words)
    {
        ASSERT_EQ(words, game.countOff(n));
    }

protected:
    CountOffGame game_sprint_1_2;
    CountOffGame game_sprint_3;
    CountOffGame game_sprint_4;
};

TEST_F(GameTest, should_count_off_given_special_num_3_5_7)
{
    ASSERT_COUNTOFF_3_5_7(1,   "1");
    ASSERT_COUNTOFF_3_5_7(2,   "2");
    ASSERT_COUNTOFF_3_5_7(3,   "ʯͷ");
    ASSERT_COUNTOFF_3_5_7(5,   "����");
    ASSERT_COUNTOFF_3_5_7(7,   "��");
    ASSERT_COUNTOFF_3_5_7(15,  "ʯͷ����");
    ASSERT_COUNTOFF_3_5_7(21,  "ʯͷ��");
    ASSERT_COUNTOFF_3_5_7(105, "ʯͷ������");

    ASSERT_COUNTOFF_3_5_7(13,   "ʯͷ");
    ASSERT_COUNTOFF_3_5_7(35,   "ʯͷ");
}

TEST_F(GameTest, should_count_off_given_special_num_5_7_9)
{
    ASSERT_COUNTOFF_5_7_9(1,   "1");
    ASSERT_COUNTOFF_5_7_9(2,   "2");
    ASSERT_COUNTOFF_5_7_9(5,   "ʯͷ");
    ASSERT_COUNTOFF_5_7_9(7,   "����");
    ASSERT_COUNTOFF_5_7_9(9,   "��");
    ASSERT_COUNTOFF_5_7_9(63,  "������");

    ASSERT_COUNTOFF_5_7_9(15,  "ʯͷ");
    ASSERT_COUNTOFF_5_7_9(35,  "ʯͷ");
}

TEST_F(GameTest, should_count_off_given_special_num_3_5_7_countof_other)
{
    ASSERT_COUNTOFF_3_5_7_EX(1,   "1");
    ASSERT_COUNTOFF_3_5_7_EX(2,   "2");
    ASSERT_COUNTOFF_3_5_7_EX(3,   "�ϻ�");
    ASSERT_COUNTOFF_3_5_7_EX(5,   "����");
    ASSERT_COUNTOFF_3_5_7_EX(7,   "��");
    ASSERT_COUNTOFF_3_5_7_EX(15,  "�ϻ�����");
    ASSERT_COUNTOFF_3_5_7_EX(21,  "�ϻ���");
    ASSERT_COUNTOFF_3_5_7_EX(105, "�ϻ����Ӽ�");

    ASSERT_COUNTOFF_3_5_7_EX(13,  "�ϻ�");
    ASSERT_COUNTOFF_3_5_7_EX(35,  "�ϻ�");
}
