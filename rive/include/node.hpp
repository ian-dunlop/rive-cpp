#ifndef _RIVE_NODE_HPP_
#define _RIVE_NODE_HPP_
#include "generated/node_base.hpp"
#include "math/mat2d.hpp"

namespace rive
{
	/// A Rive Node
	class Node : public NodeBase
	{
	private:
		Mat2D m_Transform;
		Mat2D m_WorldTransform;
		float m_RenderOpacity = 0.0f;
		Node* m_ParentNode = nullptr;

	public:
		void onAddedClean(CoreContext* context) override;
		void buildDependencies() override;
		void update(ComponentDirt value) override;
		void updateTransform();
		void updateWorldTransform();
		void markTransformDirty();
		void markWorldTransformDirty();

		/// Opacity inherited by any child of this node. This'll later get
		/// overridden by effect layers.
		virtual float childOpacity() { return m_RenderOpacity; }
		float renderOpacity() const { return m_RenderOpacity; }
		
		const Mat2D& transform() const;
		const Mat2D& worldTransform() const;

	protected:
		void xChanged() override;
		void yChanged() override;
		void rotationChanged() override;
		void scaleXChanged() override;
		void scaleYChanged() override;
		void opacityChanged() override;
	};
} // namespace rive

#endif