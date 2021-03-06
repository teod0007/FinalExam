#pragma once

#include <GameObject.h>
#include <vector>
#include "BodyNode.h"

class Cube;

class Player : public GameObject
{
public:
  ~Player();

  void Initialize(Graphics *graphics);

  void Update(float dt);
  void Draw(Graphics *graphics, Matrix4x4 relativeTo, float dt);
  bool FruitCollision(Vector3 fruitPosition);
  Transform& GetHeadTransform();
  bool& isDead();

  /**
  * Adds a new piece onto the end of our player.
  * @param The Graphics object used to initialize the new piece.
  */
  void AddBodyPiece(Graphics *graphics);

  /**
  * Sets the direction of the head of our player. The player will only move in that direction after 
  * moving at least 1 unit in the current direction.
  * @param The new direction to go in.
  */
  void SetHeadDirection(BodyNode::Direction direction);
  const BodyNode::Direction& GetHeadDirection();

protected:
  std::vector<BodyNode *> _body;
  std::vector<BodyNode::Direction> _nextDirection;
  float _difference;

  bool _newBodyPieceActive;
  bool _dead;

  float _moveSpeed;
};