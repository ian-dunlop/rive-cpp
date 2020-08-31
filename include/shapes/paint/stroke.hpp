#ifndef _RIVE_STROKE_HPP_
#define _RIVE_STROKE_HPP_
#include "generated/shapes/paint/stroke_base.hpp"
#include "shapes/path_space.hpp"
namespace rive
{
	class StrokeEffect;
	class Stroke : public StrokeBase
	{
	private:
		StrokeEffect* m_Effect = nullptr;

	public:
		RenderPaint* initPaintMutator(ShapePaintMutator* mutator) override;
		PathSpace pathSpace() const override;
		void draw(Renderer* renderer, RenderPath* path) override;
		void addStrokeEffect(StrokeEffect* effect);
		bool hasStrokeEffect() { return m_Effect != nullptr; }
		void invalidateEffects();
	protected:
		void thicknessChanged() override;
		void capChanged() override;
		void joinChanged() override;
	};
} // namespace rive

#endif