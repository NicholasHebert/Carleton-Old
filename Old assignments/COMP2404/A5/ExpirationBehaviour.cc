#include "ExpirationBehaviour.h"

Date ExpirationBehaviour::computeExpDate(Date& manufacture, int lifeSpan)
{
  return (manufacture+lifeSpan);
}
