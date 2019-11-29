#include <gtest.h>
#include "cluster.h"
#include "cluster.cpp"


TEST(Cluster, can_create_cluster_with_positive_value)
{
  ASSERT_NO_THROW(Cluster C(7));
}

TEST(Cluster, cant_create_cluster_with_unpositive_value)
{
	ASSERT_ANY_THROW(Cluster C(-1));
}

TEST(Cluster, cant_create_cluster_with_wrong_amount_of_processors)
{
	ASSERT_ANY_THROW(Cluster C(MAX_CPU+1));
}

TEST(Cluster, cant_create_cluster_with_wrong_amount_of_processors_2)
{
	ASSERT_ANY_THROW(Cluster C(MIN_CPU - 1));
}

TEST(Cluster, can_return_free_processors)
{
	Cluster C(5);
	EXPECT_EQ(5, C.Free_proc());
}

TEST(Cluster, cluster_cant_work_with_parameters_less_than_1)
{
	Cluster C(5);
	ASSERT_ANY_THROW(C.Cluster_work(0.5, 2, 2, 2););
}

TEST(Cluster, cluster_cant_work_with_parameters_bigger_than_maxsize)
{
	Cluster C(5);
	ASSERT_ANY_THROW(C.Cluster_work(5100, 2, 2, 2););
}

TEST(Cluster, task_cant_get_processors_more_than_cluster_processors)
{
	Cluster C(5);
	ASSERT_ANY_THROW(C.Cluster_work(2, 2, 7, 2));
}

TEST(Cluster, clusters_have_different_memory)
{
	Cluster C1(5), C2(6);
	EXPECT_NE(&C1, &C2);
}





