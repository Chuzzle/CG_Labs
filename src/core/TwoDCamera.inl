template<typename T, glm::precision P>
void TwoDCamera<T, P>::Update(double dt, InputHandler &ih)
{
	glm::tvec2<T, P> newMousePosition = glm::tvec2<T, P>(ih.GetMousePosition().x, ih.GetMousePosition().y);
	glm::tvec2<T, P> mouse_diff = newMousePosition - mMousePosition;
	mouse_diff.y = -mouse_diff.y;
	mMousePosition = newMousePosition;
	mouse_diff *= mMouseSensitivity;

	//if (!ih.IsMouseCapturedByUI() && (ih.GetMouseState(GLFW_MOUSE_BUTTON_LEFT) & PRESSED)) {
	//	mRotation.x -= mouse_diff.x;
	//	mRotation.y += mouse_diff.y;
	//	mWorld.SetRotateX(mRotation.y);
	//	mWorld.RotateY(mRotation.x);
	//}

	T movementModifier = ((ih.GetKeycodeState(GLFW_MOD_SHIFT) & PRESSED)) ? 0.25f : ((ih.GetKeycodeState(GLFW_MOD_CONTROL) & PRESSED)) ? 4.0f : 1.0f;
	T movement = movementModifier * T(dt) * mMovementSpeed;

	T strafe = 0.0f, levitate = 0.0f;
	if (!ih.IsKeyboardCapturedByUI()) {
		if ((ih.GetKeycodeState(GLFW_KEY_W) & PRESSED)) levitate += movement;
		if ((ih.GetKeycodeState(GLFW_KEY_S) & PRESSED)) levitate -= movement;
		if ((ih.GetKeycodeState(GLFW_KEY_A) & PRESSED)) strafe -= movement;
		if ((ih.GetKeycodeState(GLFW_KEY_D) & PRESSED)) strafe += movement;
	}

	//mWorld.Translate(mWorld.GetRight() * strafe);
	//mWorld.Translate(mWorld.GetUp() * levitate);
}
