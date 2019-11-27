#include <gtest.h>
#include "Queue.h"



TEST(Queue, can_create_queue_with_positive_length)
{
  ASSERT_NO_THROW(Queue<int> A(5));
}


TEST(Queue, cant_create_queue_with_unpositive_size)
{
	ASSERT_ANY_THROW(Queue <int> A(-1));
}

TEST(Queue, cant_create_queue_with_big_size)
{
	ASSERT_ANY_THROW(Queue <int> A(MaxSize + 1));
}

TEST(Queue, can_check_queue_is_empty)
{
	Queue <int> A(3);
	EXPECT_EQ(true, A.Empty());
}

TEST(Queue, can_check_queue_is_full)
{
	Queue <int> A(3);
	for (int i = 0; i < 3; i++)
		A.Push(1);
	EXPECT_EQ(true, A.Full());
}

TEST(Queue, cant_get_elem_from_empty_queue)
{
	Queue <int> A(3);
	ASSERT_ANY_THROW(A.Pop());
}

TEST(Queue, can_get_elem_from_queue)
{
	Queue <int> A(2);
	A.Push(3);
	A.Push(4);
	EXPECT_EQ(3, A.GetElem());
}

TEST(Queue, cant_push_element_in_full_queue)
{
	Queue <int> A(3);
	for (int i = 0; i < 3; i++)
		A.Push(1);
	ASSERT_ANY_THROW(A.Push(1));
}

TEST(Queue, can_push_element)
{
	Queue <int> A(1);
	A.Push(1);
	EXPECT_EQ(1, A.GetElem());
}

TEST(Queue, can_get_amount_of_elements)
{
	Queue <int> A(2);
	for (int i = 0; i < 2; i++)
		A.Push(1);
	EXPECT_EQ(2, A.GetSize());
}


TEST(Queue, queues_have_different_memory)
{
	Queue<int> A(3), B(4);
	EXPECT_NE(&A, &B);
}
TEST(Queue, can_push_the_element)
{
	Queue <int> A(2);
	for (int i = 0; i < 2; i++)
		A.Push(1);
	ASSERT_NO_THROW(A.Pop());
}

