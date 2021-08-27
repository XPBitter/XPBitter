
#include "Precompiled.h"
#include "SoftRenderer.h"
#include <random>
using namespace CK::DDD;

// 기즈모를 그리는 함수
void SoftRenderer::DrawGizmo3D()
{
	auto& r = GetRenderer();
	const GameEngine& g = Get3DGameEngine();

	// 뷰 기즈모 그리기
	std::vector<Vertex3D> viewGizmo = {
		Vertex3D(Vector4(Vector3::Zero)),
		Vertex3D(Vector4(Vector3::UnitX * _GizmoUnitLength)),
		Vertex3D(Vector4(Vector3::UnitY * _GizmoUnitLength)),
		Vertex3D(Vector4(Vector3::UnitZ * _GizmoUnitLength)),
	};

	Matrix4x4 viewMatRotationOnly = g.GetMainCamera().GetViewMatrixRotationOnly();
	VertexShader3D(viewGizmo, viewMatRotationOnly);

	// 축 그리기
	Vector2 v0 = viewGizmo[0].Position.ToVector2() + _GizmoPositionOffset;
	Vector2 v1 = viewGizmo[1].Position.ToVector2() + _GizmoPositionOffset;
	Vector2 v2 = viewGizmo[2].Position.ToVector2() + _GizmoPositionOffset;
	Vector2 v3 = viewGizmo[3].Position.ToVector2() + _GizmoPositionOffset;
	r.DrawLine(v0, v1, LinearColor::Red);
	r.DrawLine(v0, v2, LinearColor::Green);
	r.DrawLine(v0, v3, LinearColor::Blue);
}

// 게임 오브젝트 목록
static const std::string PlayerGo = "Player";
static const std::string Floor_1 = "Floor1";
static const std::string Floor_2 = "Floor2";
static const std::string Floor_3 = "Floor3";
static const std::string Floor_4 = "Floor4";
static const std::string Floor_5 = "Floor5";
static const std::string Floor_6 = "Floor6";
static const std::string Floor_7 = "Floor7";
static const std::string Floor_8 = "Floor8";
static const std::string Floor_9 = "Floor9";
static const std::string Floor_10 = "Floor10";


// 최초 씬 로딩을 담당하는 함수
void SoftRenderer::LoadScene3D()
{
	GameEngine& g = Get3DGameEngine();

	// 플레이어
	constexpr float playerScale = 100.f;
	// 플레이어 설정
	GameObject& Floor1 = g.CreateNewGameObject(Floor_1);
	GameObject& Floor2 = g.CreateNewGameObject(Floor_2);
	GameObject& Floor3 = g.CreateNewGameObject(Floor_3);
	GameObject& Floor4 = g.CreateNewGameObject(Floor_4);
	GameObject& Floor5 = g.CreateNewGameObject(Floor_5);
	GameObject& Floor6 = g.CreateNewGameObject(Floor_6);
	GameObject& Floor7 = g.CreateNewGameObject(Floor_7);
	GameObject& Floor8 = g.CreateNewGameObject(Floor_8);
	GameObject& Floor9 = g.CreateNewGameObject(Floor_9);
	GameObject& Floor10 = g.CreateNewGameObject(Floor_10);

	Floor1.SetMesh(GameEngine::CubeMesh);
	Floor1.GetTransform().SetPosition(Vector3(0.f, playerScale * -2.5f, 0.f));
	Floor1.GetTransform().SetScale(Vector3(playerScale, playerScale * 0.5f, playerScale));
	Floor1.GetTransform().SetRotation(Rotator(0.f, 0.f, 0.f));
	Floor1.SetColor(LinearColor::Red);
	
	Floor2.SetMesh(GameEngine::CubeMesh);
	Floor2.GetTransform().SetPosition(Vector3(0.f, playerScale * -2.f, 0.f));
	Floor2.GetTransform().SetScale(Vector3(2.f * playerScale, playerScale * 0.5f, 2.f * playerScale));
	Floor2.GetTransform().SetRotation(Rotator(0.f, 0.f, 0.f));
	Floor2.SetColor(LinearColor::Blue);

	Floor3.SetMesh(GameEngine::CubeMesh);
	Floor3.GetTransform().SetPosition(Vector3(0.f, playerScale * -1.5f, 0.f));
	Floor3.GetTransform().SetScale(Vector3(3.f * playerScale, playerScale * 0.5f, 3.f * playerScale));
	Floor3.GetTransform().SetRotation(Rotator(0.f, 0.f, 0.f));
	Floor3.SetColor(LinearColor::Green);

	Floor4.SetMesh(GameEngine::CubeMesh);
	Floor4.GetTransform().SetPosition(Vector3(0.f, playerScale * -1.f, 0.f));
	Floor4.GetTransform().SetScale(Vector3(4.f * playerScale, playerScale * 0.5f, 4.f * playerScale));
	Floor4.GetTransform().SetRotation(Rotator(0.f, 0.f, 0.f));
	Floor4.SetColor(LinearColor::Yellow);

	Floor5.SetMesh(GameEngine::CubeMesh);
	Floor5.GetTransform().SetPosition(Vector3(0.f, playerScale * -0.5f, 0.f));
	Floor5.GetTransform().SetScale(Vector3(5.f * playerScale, playerScale * 0.5f, 5.f * playerScale));
	Floor5.GetTransform().SetRotation(Rotator(0.f, 0.f, 0.f));
	Floor5.SetColor(LinearColor::Gray);

	Floor6.SetMesh(GameEngine::CubeMesh);
	Floor6.GetTransform().SetPosition(Vector3(0.f, 0.f, 0.f));
	Floor6.GetTransform().SetScale(Vector3(5.f * playerScale, playerScale * 0.5f, 5.f * playerScale));
	Floor6.GetTransform().SetRotation(Rotator(0.f, 0.f, 0.f));
	Floor6.SetColor(LinearColor::Red);

	Floor7.SetMesh(GameEngine::CubeMesh);
	Floor7.GetTransform().SetPosition(Vector3(0.f, playerScale * 0.5f, 0.f));
	Floor7.GetTransform().SetScale(Vector3(4.f * playerScale, playerScale * 0.5f, 4.f * playerScale));
	Floor7.GetTransform().SetRotation(Rotator(0.f, 0.f, 0.f));
	Floor7.SetColor(LinearColor::Blue);

	Floor8.SetMesh(GameEngine::CubeMesh);
	Floor8.GetTransform().SetPosition(Vector3(0.f, playerScale * 1.f, 0.f));
	Floor8.GetTransform().SetScale(Vector3(3.f * playerScale, playerScale * 0.5f, 3.f * playerScale));
	Floor8.GetTransform().SetRotation(Rotator(0.f, 0.f, 0.f));
	Floor8.SetColor(LinearColor::Green);

	Floor9.SetMesh(GameEngine::CubeMesh);
	Floor9.GetTransform().SetPosition(Vector3(0.f, playerScale * 1.5f, 0.f));
	Floor9.GetTransform().SetScale(Vector3(2.f * playerScale, playerScale * 0.5f, 2.f * playerScale));
	Floor9.GetTransform().SetRotation(Rotator(0.f, 0.f, 0.f));
	Floor9.SetColor(LinearColor::Yellow);

	Floor10.SetMesh(GameEngine::CubeMesh);
	Floor10.GetTransform().SetPosition(Vector3(0.f, playerScale * 2.f, 0.f));
	Floor10.GetTransform().SetScale(Vector3(playerScale, playerScale * 0.5f, playerScale));
	Floor10.GetTransform().SetRotation(Rotator(0.f, 0.f, 0.f));
	Floor10.SetColor(LinearColor::Gray);




	// 카메라 설정
	CameraObject& mainCamera = g.GetMainCamera();
	mainCamera.GetTransform().SetPosition(Vector3(0.f, 0.f, 500.f));
	mainCamera.GetTransform().SetRotation(Rotator(0.f, 0.f, 0.f));

}

// 게임 로직과 렌더링 로직이 공유하는 변수

// 게임 로직을 담당하는 함수
void SoftRenderer::Update3D(float InDeltaSeconds)
{
	// 게임 로직에서 사용하는 모듈 내 주요 레퍼런스
	GameEngine& g = Get3DGameEngine();
	const InputManager& input = g.GetInputManager();

	// 게임 로직의 로컬 변수
	static float moveSpeed = 500.f;
	static float rotateSpeed = 180.f;

	// 게임 로직에서 사용할 게임 오브젝트 레퍼런스
	GameObject& Floor1 = g.GetGameObject(Floor_1);
	GameObject& Floor2 = g.GetGameObject(Floor_2);
	GameObject& Floor3 = g.GetGameObject(Floor_3);
	GameObject& Floor4 = g.GetGameObject(Floor_4);
	GameObject& Floor5 = g.GetGameObject(Floor_5);
	GameObject& Floor6 = g.GetGameObject(Floor_6);
	GameObject& Floor7 = g.GetGameObject(Floor_7);
	GameObject& Floor8 = g.GetGameObject(Floor_8);
	GameObject& Floor9 = g.GetGameObject(Floor_9);
	GameObject& Floor10 = g.GetGameObject(Floor_10);
	
	CameraObject& camera = g.GetMainCamera();

	// 입력에 따른 플레이어 트랜스폼의 변경

    Floor1.GetTransform().AddPosition(Vector3::UnitZ * input.GetAxis(InputAxis::ZAxis) * moveSpeed * InDeltaSeconds);
    Floor1.GetTransform().AddPitchRotation(-input.GetAxis(InputAxis::WAxis) * rotateSpeed * InDeltaSeconds);
	Floor2.GetTransform().AddPosition(Vector3::UnitZ * input.GetAxis(InputAxis::ZAxis) * moveSpeed * InDeltaSeconds);
	Floor2.GetTransform().AddPitchRotation(-input.GetAxis(InputAxis::WAxis) * rotateSpeed * InDeltaSeconds);
	Floor3.GetTransform().AddPosition(Vector3::UnitZ * input.GetAxis(InputAxis::ZAxis) * moveSpeed * InDeltaSeconds);
	Floor3.GetTransform().AddPitchRotation(-input.GetAxis(InputAxis::WAxis) * rotateSpeed * InDeltaSeconds);
	Floor4.GetTransform().AddPosition(Vector3::UnitZ * input.GetAxis(InputAxis::ZAxis) * moveSpeed * InDeltaSeconds);
	Floor4.GetTransform().AddPitchRotation(-input.GetAxis(InputAxis::WAxis) * rotateSpeed * InDeltaSeconds);
	Floor5.GetTransform().AddPosition(Vector3::UnitZ * input.GetAxis(InputAxis::ZAxis) * moveSpeed * InDeltaSeconds);
	Floor5.GetTransform().AddPitchRotation(-input.GetAxis(InputAxis::WAxis) * rotateSpeed * InDeltaSeconds);
	Floor6.GetTransform().AddPosition(Vector3::UnitZ * input.GetAxis(InputAxis::ZAxis) * moveSpeed * InDeltaSeconds);
	Floor6.GetTransform().AddPitchRotation(-input.GetAxis(InputAxis::WAxis) * rotateSpeed * InDeltaSeconds);
	Floor7.GetTransform().AddPosition(Vector3::UnitZ * input.GetAxis(InputAxis::ZAxis) * moveSpeed * InDeltaSeconds);
	Floor7.GetTransform().AddPitchRotation(-input.GetAxis(InputAxis::WAxis) * rotateSpeed * InDeltaSeconds);
	Floor8.GetTransform().AddPosition(Vector3::UnitZ * input.GetAxis(InputAxis::ZAxis) * moveSpeed * InDeltaSeconds);
	Floor8.GetTransform().AddPitchRotation(-input.GetAxis(InputAxis::WAxis) * rotateSpeed * InDeltaSeconds);
	Floor9.GetTransform().AddPosition(Vector3::UnitZ * input.GetAxis(InputAxis::ZAxis) * moveSpeed * InDeltaSeconds);
	Floor9.GetTransform().AddPitchRotation(-input.GetAxis(InputAxis::WAxis) * rotateSpeed * InDeltaSeconds);
	Floor10.GetTransform().AddPosition(Vector3::UnitZ * input.GetAxis(InputAxis::ZAxis) * moveSpeed * InDeltaSeconds);
	Floor10.GetTransform().AddPitchRotation(-input.GetAxis(InputAxis::WAxis) * rotateSpeed * InDeltaSeconds);

	// 입력에 따른 카메라 트랜스폼의 변경
	camera.GetTransform().AddYawRotation(-input.GetAxis(InputAxis::XAxis) * rotateSpeed * InDeltaSeconds);
	camera.GetTransform().AddPitchRotation(-input.GetAxis(InputAxis::YAxis) * rotateSpeed * InDeltaSeconds);

}

// 애니메이션 로직을 담당하는 함수
void SoftRenderer::LateUpdate3D(float InDeltaSeconds)
{
	// 애니메이션 로직에서 사용하는 모듈 내 주요 레퍼런스
	GameEngine& g = Get3DGameEngine();

	// 애니메이션 로직의 로컬 변수
}

// 렌더링 로직을 담당하는 함수
void SoftRenderer::Render3D()
{
	// 렌더링 로직에서 사용하는 모듈 내 주요 레퍼런스
	const GameEngine& g = Get3DGameEngine();
	auto& r = GetRenderer();
	const CameraObject& mainCamera = g.GetMainCamera();

	// 배경에 기즈모 그리기
	DrawGizmo3D();

	// 렌더링 로직의 로컬 변수
	const Matrix4x4 vMatrix = mainCamera.GetViewMatrix();

	for (auto it = g.SceneBegin(); it != g.SceneEnd(); ++it)
	{
		const GameObject& gameObject = *(*it);
		if (!gameObject.HasMesh() || !gameObject.IsVisible())
		{
			continue;
		}

		// 렌더링에 필요한 게임 오브젝트의 주요 레퍼런스를 얻기
		const Mesh& mesh = g.GetMesh(gameObject.GetMeshKey());
		const TransformComponent& transform = gameObject.GetTransform();

		Matrix4x4 finalMatrix = vMatrix * transform.GetModelingMatrix();

		// 메시 그리기
		DrawMesh3D(mesh, finalMatrix, gameObject.GetColor());

		// 뷰 공간에서의 플레이어 위치를 화면에 표시
		if (gameObject == PlayerGo)
		{
			Vector3 viewPosition = vMatrix * transform.GetPosition();
			r.PushStatisticText("View : " + viewPosition.ToString());
		}
	}
}

// 메시를 그리는 함수
void SoftRenderer::DrawMesh3D(const Mesh& InMesh, const Matrix4x4& InMatrix, const LinearColor& InColor)
{
	size_t vertexCount = InMesh.GetVertices().size();
	size_t indexCount = InMesh.GetIndices().size();
	size_t triangleCount = indexCount / 3;

	// 렌더러가 사용할 정점 버퍼와 인덱스 버퍼로 변환
	std::vector<Vertex3D> vertices(vertexCount);
	std::vector<size_t> indice(InMesh.GetIndices());
	for (size_t vi = 0; vi < vertexCount; ++vi)
	{
		vertices[vi].Position = Vector4(InMesh.GetVertices()[vi]);

		if (InMesh.HasColor())
		{
			vertices[vi].Color = InMesh.GetColors()[vi];
		}

		if (InMesh.HasUV())
		{
			vertices[vi].UV = InMesh.GetUVs()[vi];
		}
	}

	// 정점 변환 진행
	VertexShader3D(vertices, InMatrix);

	// 삼각형 별로 그리기
	for (int ti = 0; ti < triangleCount; ++ti)
	{
		int bi0 = ti * 3, bi1 = ti * 3 + 1, bi2 = ti * 3 + 2;
		std::vector<Vertex3D> tvs = { vertices[indice[bi0]] , vertices[indice[bi1]] , vertices[indice[bi2]] };

		size_t triangles = tvs.size() / 3;
		for (size_t ti = 0; ti < triangles; ++ti)
		{
			size_t si = ti * 3;
			std::vector<Vertex3D> sub(tvs.begin() + si, tvs.begin() + si + 3);
			DrawTriangle3D(sub, InColor, FillMode::Color);
		}
	}
}

// 삼각형을 그리는 함수
void SoftRenderer::DrawTriangle3D(std::vector<Vertex3D>& InVertices, const LinearColor& InColor, FillMode InFillMode)
{
	auto& r = GetRenderer();
	const GameEngine& g = Get3DGameEngine();

	LinearColor finalColor = _WireframeColor;
	if (InColor != LinearColor::Error)
	{
		finalColor = InColor;
	}

	r.DrawLine(InVertices[0].Position, InVertices[1].Position, finalColor);
	r.DrawLine(InVertices[0].Position, InVertices[2].Position, finalColor);
	r.DrawLine(InVertices[1].Position, InVertices[2].Position, finalColor);
}

