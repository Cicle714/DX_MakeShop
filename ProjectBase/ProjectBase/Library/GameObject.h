#pragma once
/// <summary>
/// ゲームオブジェクトの基底クラス
/// </summary>
/// <author>N.Hanai</author>

#include <DxLib.h>
#include <string>
#include "SceneBase.h"
#include "ObjectManager.h"

class GameObject
{
public:
	GameObject() : pParent(nullptr), tag("") , destroy(false), dontDestroy(false), drawOrder(0), priority(0) {}
	GameObject(GameObject* object) : pParent(object), tag(""), destroy(false), dontDestroy(false), drawOrder(0), priority(0) {}
	virtual ~GameObject() {}

	/// <summary>
	/// オブジェクトを生成後、最初にUpdate()の前に呼ばれます
	/// </summary>
	virtual void Start() {}

	/// <summary>
	/// 毎フレームの更新処理のために呼ばれます
	/// </summary>
	virtual void Update() {}

	/// <summary>
	/// 毎フレームの描画処理のために呼ばれます
	/// </summary>
	virtual void Draw() {}

	/// <summary>
	/// 自分のインスタンスを削除する時に呼び出してください
	/// 次回のUpdateの前に削除されます
	/// </summary>
	void DestroyMe() { destroy = true; }

	bool DestroyRequested() { return destroy; }

	/// <summary>
	/// シーンが変わるときに削除しないようにします
	/// </summary>
	void DontDestroyOnLoad(bool dont = true) { dontDestroy = dont; }

	inline bool IsDontDestroy() { return dontDestroy; }
	/// <summary>
	/// 処理の優先順位を指定します
	/// 数値が高い順に実行されます
	/// 何も指定しなければ、０です
	/// </summary>
	/// <param name="pri">優先順位</param>
	void SetPriority(int pri) {
		priority = pri;
		ObjectManager::SortByPriority();
	}

	inline int GetPriority() { return priority;	}

	/// <summary>
	/// 描画の優先順位を指定します
	/// 数値が高いほど、後から描画されるので、
	/// 2Dであれば、手前に表示されます
	/// 何も指定しなければ０です
	/// </summary>
	/// <param name="odr">描画順位</param>
	void SetDrawOrder(int order) {
		drawOrder = order;
		ObjectManager::SortByDrawOrder();
	}

	inline int GetDrawOrder() {	return drawOrder; }
	/// <summary>
	/// タグをつける
	/// タグは１つだけ付けることができます
	/// </summary>
	/// <param name="_tag">タグ</param>
	void SetTag(std::string _tag) { tag = _tag; }

	/// <summary>
	/// 指定されたタグと同じかを返す
	/// </summary>
	/// <param name="_tag">タグ</param>
	/// <returns>同じであればtrue</returns>
	bool IsTag(std::string _tag) const { return tag == _tag; }

	/// <summary>
	/// 親のオブジェクトを返す
	/// </summary>
	/// <returns>親オブジェクトのポインター</returns>
	GameObject* GetParent() const { return pParent; }

	/// <summary>
	/// 親のオブジェクトを設定する
	/// </summary>
	/// <returns>親オブジェクトのポインター</returns>
	void SetParent(GameObject* _parent) { pParent = _parent; }
private:
	GameObject* pParent; // 親のオブジェクト
	std::string tag;     // タグ
	bool destroy;
	bool dontDestroy;
	int drawOrder;
	int priority;
};
