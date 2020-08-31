#include "shapes/paint/trim_path.hpp"
#include "shapes/paint/stroke.hpp"

using namespace rive;

StatusCode TrimPath::onAddedClean(CoreContext* context)
{
	if (parent()->is<Stroke>())
	{
		return StatusCode::InvalidObject;
	}

	parent()->as<Stroke>()->addStrokeEffect(this);

	return StatusCode::Ok;
}

RenderPath* TrimPath::effectPath(MetricsPath* source)
{
	if (m_RenderPath != nullptr)
	{
		return m_RenderPath;
	}
	m_TrimmedPath = makeRenderPath();

	m_RenderPath = m_TrimmedPath;
	return m_RenderPath;
}

void TrimPath::invalidateEffect()
{
	m_RenderPath = nullptr;
	parent()->as<Stroke>()->parent()->addDirt(ComponentDirt::Paint);
}

void TrimPath::startChanged() { invalidateEffect(); }
void TrimPath::endChanged() { invalidateEffect(); }
void TrimPath::offsetChanged() { invalidateEffect(); }
void TrimPath::modeValueChanged() { invalidateEffect(); }